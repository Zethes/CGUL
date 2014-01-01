// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HTTPRequest.cpp
 *  @brief Implements Network::HTTPRequest
 */

#include "DNS.hpp"
#include "HTTPRequest.hpp"
#include "HTTPEnums.hpp"
#include "../Exceptions/NetworkException.hpp"
#include "../Containers/Vector.hpp"
#include "../Utility/Timer.hpp"

CGUL::Network::Header::Header() :
    age             (0),
    allow           (0),
    charset         (0),
    connection      (0),
    contentEncoding (0),
    contentLength   (0),
    contentRangeMin (0),
    contentRangeMax (0),
    refresh         (0),
    retryAfter      (0),
    setCookieValue  (0),
    setCookieVersion(0),
    status          (0),
    transferEncoding(0)
{
}

CGUL::Network::HTTPRequest::HTTPRequest(const HTTPRequest& copy)
{
    // private
}

bool CGUL::Network::HTTPRequest::PerformRequest(UInt32 timeout)
{
    response = "";
    responseHead = "";
    responseBody = "";

    if (!sock->IsConnected())
    {
        throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::SOCKET_INVALID);
    }

    sock->Send((const void*)request.GetCString(), request.GetSize());

    char buffer[1024];

    // Wait for the response.
    Timer timeoutTimer;
    timeoutTimer.Start();
    while (sock->Peek(buffer, 1) == 0 && (timeoutTimer.GetElapsedMilliseconds() < timeout || timeout == 0))
    {
        if (!sock->IsConnected())
        {
            throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::SOCKET_INVALID);
        }
    }
    timeoutTimer.Stop();

    if (timeoutTimer.GetElapsedMilliseconds() >= timeout && timeout != 0)
    {
        throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::TIMEOUT);
    }

    //Get the headers length.
    int headSize = 0;
    sock->Peek(buffer, 1024);
    CGUL::String bufferString = buffer;
    headSize = bufferString.FindFirstOf("\r\n\r\n")+4;

    //Get the reponse's head.
    char* bufferHead = new char[headSize];
    sock->Receive(bufferHead, headSize);
    responseHead += bufferHead;

    //Parse the Response Header
    ParseResponseHead();

    //Get the reponse's body.
    int amount = 0;

    switch (header.transferEncoding)
    {
        case HTTPTransferEncoding::CONTENT_LENGTH:
        {
            unsigned int count = 0;
            while (sock->IsConnected())
            {
                unsigned int size = 1024;
                if (count + size > header.contentLength)
                {
                    size = header.contentLength - count;
                }

                char* buff = new char[size];
                amount = sock->Receive((void*)buff, size);
                count += amount;
                if (amount > 0)
                {
                    responseBody += EncodeString(buff, size);
                }

                if (count >= header.contentLength)
                {
                    break;
                }
            }
            break;
        }

        case HTTPTransferEncoding::CHUNKED:
        {
            char * sizeBuffer = new char[64];

            while (sock->IsConnected())
            {
                //Get the size.
                amount = sock->Peek(sizeBuffer, 64);
                if (amount <= 0)
                {
                    break;
                }

                String sizeString = "";
                for (int i = 0; i < amount; i++)
                {
                    if (sizeBuffer[i] == '\r')
                    {
                        if (sizeBuffer[i+1] == '\n')
                        {
                            break;
                        }
                        throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::UNKNOWN);
                    }
                    else
                    {
                        sizeString += sizeBuffer[i];
                    }
                }
                //Convert from hex to decimal
                unsigned int size = 0;
                for (unsigned j = 0; j < sizeString.GetLength(); j++)
                {
                    char code = sizeString[sizeString.GetLength()-j-1];
                    if (code >= 48 && code <= 57) //Number
                    {
                        size += (code - 48)*((j == 0) ? 1 : 16*j);
                    }
                    if (code >= 65 && code <= 70) //A-F
                    {
                        size += (code - 55)*((j == 0) ? 1 : 16*j);
                    }
                    if (code >= 97 && code <= 102) //a-f
                    {
                        size += (code - 87)*((j == 0) ? 1 : 16*j);
                    }
                }
                sock->Receive(sizeBuffer, sizeString.GetLength()+2);

                if (size == 0) //If the size is 0, then we are done
                {
                    break;
                }
                size += 2;

                //Otherwise receive the next chunk and add a new line (\r\n)
                char* buff = new char[size];
                amount = sock->Receive((void*)buff, size);
                responseBody += EncodeString(buff, size);
            }
            break;
        }

        default:
        {
            throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::UNKNOWN_TRANSFER_ENCODING);
            break;
        }
    }

    response = responseHead + responseBody;

    if (header.connection == Network::HTTPConnections::CLOSE)
    {
        Close();
    }

    return true;
}

void CGUL::Network::HTTPRequest::ParseResponseHead()
{
    header = Header();

    //Setup defaults:
    header.transferEncoding = HTTPTransferEncoding::CONTENT_LENGTH;

    //Split the lines to parse one by one.
    Vector< String > lines;
    responseHead.Explode("\n", &lines);
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        Vector< String > parts;
        lines[i].Explode(" ", &parts);
        for (unsigned int j = 0; j < parts.size(); j++)
        {
            parts[j].Trim();
        }

        //Begin parsing.
        if (i == 0) //First line contains the status code.
        {
            header.status = parts[1].To<int>(HTTPStatusCodes::UNKNOWN);
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.statusString += parts[j] + " ";
            }
            header.statusString.Trim();
        }
        else if (parts[0] == "Access-Control-Allow-Origin:")
        {
            header.accessControlAllowOrigin = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.accessControlAllowOrigin += parts[j] + " ";
            }
            header.accessControlAllowOrigin.Trim();
        }
        else if (parts[0] == "Accept-Ranges:")
        {
            header.acceptRanges = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.acceptRanges += parts[j] + " ";
            }
            header.acceptRanges.Trim();
        }
        else if (parts[0] == "Age:")
        {
            header.ageString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.ageString += parts[j] + " ";
            }
            header.ageString.Trim();

            header.age = header.ageString.To<int>(-1);
        }
        else if (parts[0] == "Allow:")
        {
            header.allow = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.allow += parts[j] + " ";
            }
            header.allow.Trim();
        }
        else if (parts[0] == "Cache-Control:")
        {
            header.cacheControl = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.cacheControl += parts[j] + " ";
            }
            header.cacheControl.Trim();
        }
        else if (parts[0] == "Connection:")
        {
            header.contentEncodingString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentEncodingString += parts[j] + " ";
            }
            header.contentEncodingString.Trim();

            if (header.connectionString == "close")
            {
                header.connection = HTTPConnections::CLOSE;
            }
            else if (header.connectionString == "Keep-Alive")
            {
                header.connection = HTTPConnections::KEEP_ALIVE;
            }
            else
            {
                header.connection = HTTPConnections::UNKNOWN;
            }
        }
        else if (parts[0] == "Content-Disposition:")
        {
            header.contentDisposition = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentDisposition += parts[j] + " ";
            }
            header.contentDisposition.Trim();
        }
        else if (parts[0] == "Content-Encoding:")
        {
            header.connectionString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.connectionString += parts[j] + " ";
            }
            header.connectionString.Trim();

            if (header.contentEncodingString == "compress")
            {
                header.contentEncoding = HTTPContentEncoding::COMPRESS;
            }
            else if (header.contentEncodingString == "deflate")
            {
                header.contentEncoding = HTTPContentEncoding::DEFLATE;
            }
            else if (header.contentEncodingString == "exi")
            {
                header.contentEncoding = HTTPContentEncoding::EXI;
            }
            else if (header.contentEncodingString == "gzip")
            {
                header.contentEncoding = HTTPContentEncoding::GZIP;
            }
            else if (header.contentEncodingString == "identity")
            {
                header.contentEncoding = HTTPContentEncoding::IDENTITY;
            }
            else if (header.contentEncodingString == "pack200-gzip")
            {
                header.contentEncoding = HTTPContentEncoding::PACK200_GZIP;
            }
            else if (header.contentEncodingString == "sdch")
            {
                header.contentEncoding = HTTPContentEncoding::SDCH;
            }
            else if (header.contentEncodingString == "bzip2")
            {
                header.contentEncoding = HTTPContentEncoding::BZIP2;
            }
            else if (header.contentEncodingString == "peerdist")
            {
                header.contentEncoding = HTTPContentEncoding::PEERDIST;
            }
            else if (header.contentEncodingString == "lzma")
            {
                header.contentEncoding = HTTPContentEncoding::LZMA;
            }
            else
            {
                header.contentEncoding = HTTPContentEncoding::UNKNOWN;
            }
        }
        else if (parts[0] == "Content-Language:")
        {
            header.contentLanguage = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentLanguage += parts[j] + " ";
            }
            header.contentLanguage.Trim();
        }
        else if (parts[0] == "Content-Length:")
        {
            header.contentLength = parts[1].To<UInt>(0);

            header.contentLengthString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentLengthString += parts[j] + " ";
            }
            header.contentLengthString.Trim();
        }
        else if (parts[0] == "Content-Location:")
        {
            header.contentLocation = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentLocation += parts[j] + " ";
            }
            header.contentLocation.Trim();
        }
        else if (parts[0] == "Content-MD5:")
        {
            header.contentMD5 = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentMD5 += parts[j] + " ";
            }
            header.contentMD5.Trim();
        }
        else if (parts[0] == "Content-Range:")
        {
            header.contentRangeString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentRangeString += parts[j] + " ";
            }
            header.contentRangeString.Trim();
        }
        else if (parts[0] == "Content-Type:")
        {
            header.contentType = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.contentType += parts[j] + " ";
                if (parts[j].SubString(0,8) == "charset=")
                {
                    header.charsetString = parts[j].SubString(8);
                    header.charsetString.Trim();
                    header.charsetString.ToUpper();

                    if (header.charsetString == "ISO-8859-1")
                    {
                        header.charset = HTTPCharsets::ISO_8859_1;
                    }
                    else if (header.charsetString == "ISO-8859-2")
                    {
                        header.charset = HTTPCharsets::ISO_8859_2;
                    }
                    else if (header.charsetString == "ISO-8859-3")
                    {
                        header.charset = HTTPCharsets::ISO_8859_3;
                    }
                    else if (header.charsetString == "ISO-8859-4")
                    {
                        header.charset = HTTPCharsets::ISO_8859_4;
                    }
                    else if (header.charsetString == "ISO-8859-5")
                    {
                        header.charset = HTTPCharsets::ISO_8859_5;
                    }
                    else if (header.charsetString == "ISO-8859-6")
                    {
                        header.charset = HTTPCharsets::ISO_8859_6;
                    }
                    else if (header.charsetString == "ISO-8859-7")
                    {
                        header.charset = HTTPCharsets::ISO_8859_7;
                    }
                    else if (header.charsetString == "ISO-8859-8")
                    {
                        header.charset = HTTPCharsets::ISO_8859_8;
                    }
                    else if (header.charsetString == "ISO-8859-9")
                    {
                        header.charset = HTTPCharsets::ISO_8859_9;
                    }
                    else if (header.charsetString == "ISO-8859-10")
                    {
                        header.charset = HTTPCharsets::ISO_8859_10;
                    }
                    else if (header.charsetString == "ISO-8859-15")
                    {
                        header.charset = HTTPCharsets::ISO_8859_15;
                    }
                    else if (header.charsetString == "ISO-2022-JP")
                    {
                        header.charset = HTTPCharsets::ISO_2022_JP;
                    }
                    else if (header.charsetString == "ISO-2022-JP-2")
                    {
                        header.charset = HTTPCharsets::ISO_2022_JP_2;
                    }
                    else if (header.charsetString == "ISO-2022-KR")
                    {
                        header.charset = HTTPCharsets::ISO_2022_KR;
                    }
                    else if (header.charsetString == "UTF-8")
                    {
                        header.charset = HTTPCharsets::UTF_8;
                    }
                    else if (header.charsetString == "UTF-16")
                    {
                        header.charset = HTTPCharsets::UTF_16;
                    }
                    else
                    {
                        header.charset = HTTPCharsets::UNKNOWN;
                    }
                }
                else if (parts[j].FindFirstOf(";") > 0)
                {
                    header.mime = parts[j].SubString(0,parts[j].FindFirstOf(";"));
                }
            }
            header.contentType.Trim();
        }
        else if (parts[0] == "Date:")
        {
            header.date = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.date += parts[j] + " ";
            }
            header.date.Trim();
        }
        else if (parts[0] == "ETag:")
        {
            header.eTag = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.eTag += parts[j] + " ";
            }
            header.eTag.Trim();
        }
        else if (parts[0] == "Expires:")
        {
            header.expires = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.expires += parts[j] + " ";
            }
            header.expires.Trim();
        }
        else if (parts[0] == "Last-Modified:")
        {
            header.lastModified = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.lastModified += parts[j] + " ";
            }
            header.lastModified.Trim();
        }
        else if (parts[0] == "Link:")
        {
            header.link = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.link += parts[j] + " ";
            }
            header.link.Trim();
        }
        else if (parts[0] == "Location:")
        {
            header.location = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.location += parts[j] + " ";
            }
            header.location.Trim();
        }
        else if (parts[0] == "P3P:")
        {
            header.p3p = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.p3p += parts[j] + " ";
            }
            header.p3p.Trim();
        }
        else if (parts[0] == "Pragma:")
        {
            header.pragma = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.pragma += parts[j] + " ";
            }
            header.pragma.Trim();
        }
        else if (parts[0] == "Proxy-Authenticate:")
        {
            header.proxyAuthenticate = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.proxyAuthenticate += parts[j] + " ";
            }
            header.proxyAuthenticate.Trim();
        }
        else if (parts[0] == "Refresh:")
        {
            header.refreshString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.refreshString += parts[j] + " ";
                if (parts[j].SubString(0,4) == "url=")
                {
                    header.refreshUrl = parts[j].SubString(4);
                    header.refreshUrl.Trim();
                }
                else if (parts[j].FindFirstOf(";") > 0)
                {
                    header.refresh = parts[j].SubString(0,parts[j].FindFirstOf(";")).To<int>(0);
                }
            }
            header.refreshString.Trim();
        }
        else if (parts[0] == "Retry-After:")
        {
            header.retryAfterString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.retryAfterString += parts[j] + " ";
            }
            header.retryAfterString.Trim();

            header.retryAfter = header.retryAfterString.To<int>(0);
        }
        else if (parts[0] == "Server:")
        {
            header.server = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.server += parts[j] + " ";
            }
            header.server.Trim();
        }
        else if (parts[0] == "Set-Cookie:")
        {
            header.setCookie = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.setCookie += parts[j] + " ";
            }
            header.setCookie.Trim();

            //TODO: Parse Set-Cookie
        }
        else if (parts[0] == "Status:")
        {
            header.status = parts[1].To<int>(0);

            header.statusString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.statusString += parts[j] + " ";
            }
            header.statusString.Trim();
        }
        else if (parts[0] == "Strict-Transport-Security:")
        {
            header.strictTransportSecurity = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.strictTransportSecurity += parts[j] + " ";
            }
            header.strictTransportSecurity.Trim();
        }
        else if (parts[0] == "Trailer:")
        {
            header.trailer = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.trailer += parts[j] + " ";
            }
            header.trailer.Trim();
        }
        else if (parts[0] == "Transfer-Encoding:")
        {
            header.transferEncodingString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.transferEncodingString += parts[j] + " ";
            }
            header.transferEncodingString.Trim();

            if (header.transferEncodingString == "chunked")
            {
                header.transferEncoding = HTTPTransferEncoding::CHUNKED;
            }
            else if (header.transferEncodingString == "compress")
            {
                header.transferEncoding = HTTPTransferEncoding::COMPRESS;
            }
            else if (header.transferEncodingString == "deflate")
            {
                header.transferEncoding = HTTPTransferEncoding::DEFLATE;
            }
            else if (header.transferEncodingString == "gzip")
            {
                header.transferEncoding = HTTPTransferEncoding::GZIP;
            }
            else if (header.transferEncodingString == "identity")
            {
                header.transferEncoding = HTTPTransferEncoding::IDENTITY;
            }
            else
            {
                header.transferEncoding = HTTPTransferEncoding::UNKNOWN;
            }
        }
        else if (parts[0] == "Vary:")
        {
            header.vary = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.vary += parts[j] + " ";
            }
            header.vary.Trim();
        }
        else if (parts[0] == "Via:")
        {
            header.via = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.via += parts[j] + " ";
            }
            header.via.Trim();
        }
        else if (parts[0] == "Warning:")
        {
            header.warning = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.warning += parts[j] + " ";
            }
            header.warning.Trim();
        }
        else if (parts[0] == "WWW-Authenticate:")
        {
            header.wwwAuthenticate = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.wwwAuthenticate += parts[j] + " ";
            }
            header.wwwAuthenticate.Trim();
        }
    }
}

CGUL::String CGUL::Network::HTTPRequest::EncodeString(const char* buffer, UInt len)
{
    String ret = "";

    switch (header.charset)
    {
        case HTTPCharsets::UTF_8: //Char* to UTF-8
        {
            for (unsigned int i = 0; i < len; i++)
            {
                if (buffer[i] == '\\' && i+1 < len)
                {
                    if (buffer[i+1] == 0x27)
                    {
                        ret += 0x27;
                        i++;
                    }
                    else if (buffer[i+1] == '"')
                    {
                        ret += "\"";
                        i++;
                    }
                    else if (buffer[i+1] == '?')
                    {
                        ret += "\?";
                        i++;
                    }
                    else if (buffer[i+1] == '\\')
                    {
                        ret += "\\";
                        i++;
                    }
                    else if (buffer[i+1] == '0')
                    {
                        ret += "\0";
                        i++;
                    }
                    else if (buffer[i+1] == 'a')
                    {
                        ret += "\a";
                        i++;
                    }
                    else if (buffer[i+1] == 'b')
                    {
                        ret += "\b";
                        i++;
                    }
                    else if (buffer[i+1] == 'f')
                    {
                        ret += "\f";
                        i++;
                    }
                    else if (buffer[i+1] == 'n')
                    {
                        ret += "\n";
                        i++;
                    }
                    else if (buffer[i+1] == 'r')
                    {
                        ret += "\r";
                        i++;
                    }
                    else if (buffer[i+1] == 't')
                    {
                        ret += "\t";
                        i++;
                    }
                    else if (buffer[i+1] == 'v')
                    {
                        ret += "\v";
                        i++;
                    }
                    else if (buffer[i+1] == 'X' && i+3 < len)
                    {
                        ret += "\f";
                        i++;

                        char codePoint = 0;
                        for (unsigned j = 0; j < 2; j++)
                        {
                            char code = buffer[i+3-j];
                            if (code >= 48 && code <= 57) //Number
                            {
                                codePoint += (code-48)*((j == 0) ? 1 : 16*j);
                            }
                            if (code >= 65 && code <= 70) //A-F
                            {
                                codePoint += (code-55)*((j == 0) ? 1 : 16*j);
                            }
                            if (code >= 97 && code <= 102) //a-f
                            {
                                codePoint += (code-87)*((j == 0) ? 1 : 16*j);
                            }
                        }

                        ret += codePoint;
                        i += 3;
                    }
                    else if (buffer[i+1] == 'u' && i+5 < len)
                    {
                        UInt32 codePoint = 0;
                        for (unsigned j = 0; j < 4; j++)
                        {
                            char code = buffer[i+5-j];
                            if (code >= 48 && code <= 57) //Number
                            {
                                codePoint += (code-48)*((j == 0) ? 1 : 16*j);
                            }
                            if (code >= 65 && code <= 70) //A-F
                            {
                                codePoint += (code-55)*((j == 0) ? 1 : 16*j);
                            }
                            if (code >= 97 && code <= 102) //a-f
                            {
                                codePoint += (code-87)*((j == 0) ? 1 : 16*j);
                            }
                        }

                        ret += CGUL::String::FromCodePoint(codePoint);
                        i += 5;
                    }
                }
                else
                {
                    ret += buffer[i];
                }
            }
        }
        break;

        default:    //Unknown charset, just set the string to the buffer.
            ret.Set(buffer);
            break;
    }
    return ret;
}

CGUL::Network::HTTPRequest::HTTPRequest()
{
    sock = new SocketTCP();
}

CGUL::Network::HTTPRequest::~HTTPRequest()
{
    Close();
    delete sock;
}

void CGUL::Network::HTTPRequest::Http(const String& url)
{
    host = url;

    DNS dns;
    Vector< Network::IPAddress > lookup;
    dns.Lookup(url, &lookup);
    if (lookup.size() == 0)
    {
        return;
    }

    sock->Connect(lookup[0], 80);
}

void CGUL::Network::HTTPRequest::Connect(const IPAddress& ip, int port)
{
    host = ip.ToString();
    sock->Connect(ip, port);
}

#ifdef OpenSSL_FOUND
void CGUL::Network::HTTPRequest::Https(const String& url)
{
    host = url;

    DNS dns;
    Vector< Network::IPAddress > lookup;
    dns.Lookup(url, &lookup);
    if (lookup.size() == 0)
    {
        return;
    }

    sock->ConnectSSL(IPAddress(lookup[0]), 443);
}

void CGUL::Network::HTTPRequest::ConnectSSL(const IPAddress& ip, int port)
{
    host = ip.ToString();
    sock->ConnectSSL(ip, port);
}
#endif

void CGUL::Network::HTTPRequest::Close()
{
    sock->Close();
}

bool CGUL::Network::HTTPRequest::Request(String req, UInt32 timeout)
{
    request = req;
    request += "\n\r\n";

    return PerformRequest(timeout);
}

bool CGUL::Network::HTTPRequest::Get(String page, UInt32 timeout)
{
    request = "";
    request += "GET ";
    request += page + " HTTP/1.1";
    request += "\r\nHost: ";
    request += host;
    request += "\r\nX-Target-URI: http://";
    request += host;
    request += "\r\nConnection: Keep-Alive";
    request += "\r\n\r\n";

    return PerformRequest(timeout);
}

bool CGUL::Network::HTTPRequest::Head(String page, UInt32 timeout)
{
    request = "";
    request += "HEAD ";
    request += page + " HTTP/1.1";
    request += "\r\nHost: ";
    request += host;
    request += "\r\nConnection: Keep-Alive";
    request += "\r\n\r\n";

    return PerformRequest(timeout);
}

bool CGUL::Network::HTTPRequest::Post(String page, CGUL::String content, UInt32 timeout)
{
    request = "";
    request += "POST ";
    request += page + " HTTP/1.1";
    request += "\r\nHost: ";
    request += host;
    request += "\r\nConnection: Keep-Alive";
    request += "\r\nContent-Length: ";
    request += content.GetSize();
    request += "\r\nContent-Type: application/x-www-form-urlencoded; charset=UTF-8";
    request += "\r\n\r\n";
    request += content;

    return PerformRequest(timeout);
}

bool CGUL::Network::HTTPRequest::IsConnected()
{
    return sock->IsConnected();
}
CGUL::Network::SocketTCP* CGUL::Network::HTTPRequest::GetSocket()
{
    return sock;
}

CGUL::String CGUL::Network::HTTPRequest::GetRequest()
{
    return request;
}
CGUL::String CGUL::Network::HTTPRequest::GetResponse()
{
    return response;
}
CGUL::Network::Header CGUL::Network::HTTPRequest::GetHeader()
{
    return header;
}
CGUL::String CGUL::Network::HTTPRequest::GetResponseHead()
{
    return responseHead;
}
CGUL::String CGUL::Network::HTTPRequest::GetResponseBody()
{
    return responseBody;
}
