/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

/** @file HTTPRequest.cpp
 *  @brief Implements Network::HTTPRequest
 */

#include "DNS.h"
#include "HTTPRequest.h"
#include "HTTPEnums.h"
#include "../Exceptions/NetworkException.h"
#include "../Utility/Timer.h"

bool Jatta::Network::HTTPRequest::PerformRequest(int timeout)
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
            throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::SOCKET_INVALID);
    }
    timeoutTimer.Stop();

    if (timeoutTimer.GetElapsedMilliseconds() >= timeout && timeout != 0)
        throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::TIMEOUT);

    //Get the headers length.
    int headSize = 0;
    sock->Peek(buffer, 1024);
    Jatta::String bufferString = buffer;
    headSize = bufferString.FindFirstOf("\r\n\r\n")+4;

    //Get the reponse's head.
    char* bufferHead = new char[headSize];
    sock->Receive(bufferHead, headSize);
    responseHead += bufferHead;

    //Parse the Response Header
    ParseResponseHead();

    //Get the reponse's body.
    int count = 0;
    int amount = 0;

    switch (header.TransferEncoding)
    {
        case HTTPTransferEncoding::CONTENT_LENGTH:
        {
            char * bufferBody = new char[1024];
            while (sock->IsConnected())
            {
                int size = 1024;
                if (count + size > header.ContentLength)
                    size = header.ContentLength - count;

                char* buff = new char[size];
                amount = sock->Receive((void*)buff, size);
                count += amount;
                if (amount > 0)
                    responseBody += EncodeString(buff, size);

                if (count >= header.ContentLength)
                    break;
            }
        }
        break;

        case HTTPTransferEncoding::CHUNKED:
        {
            char * sizeBuffer = new char[64];

            while (sock->IsConnected())
            {
                //Get the size.
                amount = sock->Peek(sizeBuffer, 64);
                if (amount <= 0)
                    break;

                String sizeString = "";
                for (unsigned int i = 0; i < amount; i++)
                {
                    if (sizeBuffer[i] == '\r')
                    {
                        if (sizeBuffer[i+1] == '\n')
                            break;
                        throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::UNKNOWN);
                    }
                    else
                        sizeString += sizeBuffer[i];
                }
                //Convert from hex to decimal
                unsigned int size = 0;
                for (unsigned j = 0; j < sizeString.GetLength(); j++)
                {
                    char code = sizeString[sizeString.GetLength()-j-1];
                    if (code >= 48 && code <= 57) //Number
                        size += (code-48)*((j == 0) ? 1 : 16*j);
                    if (code >= 65 && code <= 70) //A-F
                        size += (code-55)*((j == 0) ? 1 : 16*j);
                    if (code >= 97 && code <= 102) //a-f
                        size += (code-87)*((j == 0) ? 1 : 16*j);
                }
                sock->Receive(sizeBuffer, sizeString.GetLength()+2);

                if (size == 0) //If the size is 0, then we are done
                    break;
                size += 2;

                //Otherwise receive the next chunk and add a new line (\r\n)
                char* buff = new char[size];
                amount = sock->Receive((void*)buff, size);
                count += amount;
                responseBody += EncodeString(buff, size);
            }
        }
        break;

        default:
            throw NetworkException(NetworkExceptionCode::FAILED_HTTP_REQUEST, NetworkExceptionReason::UNKNOWN_TRANSFER_ENCODING);
            break;
    }

    response = responseHead + responseBody;

    if (header.Connection == Network::HTTPConnections::CLOSE)
        Close();

    return true;
}

void Jatta::Network::HTTPRequest::ParseResponseHead()
{
    header = Header();

    //Setup defaults:
    header.TransferEncoding = HTTPTransferEncoding::CONTENT_LENGTH;

    //Split the lines to parse one by one.
    std::vector<String> lines = responseHead.Explode("\n");
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        std::vector<String> parts = lines[i].Explode(" ");
        for (unsigned int j = 0; j < parts.size(); j++)
            parts[j].Trim();

        //Begin parsing.
        if (i == 0) //First line contains the status code.
        { 
            header.Status = parts[1].To<int>(HTTPStatusCodes::UNKNOWN);
            for (unsigned int j = 1; j < parts.size(); j++)
                header.StatusString += parts[j] + " ";
            header.StatusString.Trim();
        }
        else if (parts[0] == "Access-Control-Allow-Origin:") 
        {
            header.AccessControlAllowOrigin = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.AccessControlAllowOrigin += parts[j] + " ";
            header.AccessControlAllowOrigin.Trim();
        }
        else if (parts[0] == "Accept-Ranges:") 
        {
            header.AcceptRanges = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.AcceptRanges += parts[j] + " ";
            header.AcceptRanges.Trim();
        }
        else if (parts[0] == "Age:") 
        {
            header.AgeString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.AgeString += parts[j] + " ";
            header.AgeString.Trim();

            header.Age = header.AgeString.To<int>(-1);
        }
        else if (parts[0] == "Allow:") 
        {
            header.Allow = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Allow += parts[j] + " ";
            header.Allow.Trim();
        }
        else if (parts[0] == "Cache-Control:") 
        {
            header.CacheControl = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.CacheControl += parts[j] + " ";
            header.CacheControl.Trim();
        }
        else if (parts[0] == "Connection:")
        {
            header.ContentEncodingString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentEncodingString += parts[j] + " ";
            header.ContentEncodingString.Trim();

            if (header.ConnectionString == "close")
                header.Connection = HTTPConnections::CLOSE;
            else if (header.ConnectionString == "Keep-Alive")
                header.Connection = HTTPConnections::KEEP_ALIVE;
            else
                header.Connection = HTTPConnections::UNKNOWN;
        }
        else if (parts[0] == "Content-Disposition:") 
        {
            header.ContentDisposition = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentDisposition += parts[j] + " ";
            header.ContentDisposition.Trim();
        }
        else if (parts[0] == "Content-Encoding:")
        {
            header.ConnectionString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ConnectionString += parts[j] + " ";
            header.ConnectionString.Trim();

            if (header.ContentEncodingString == "compress")
                header.ContentEncoding = HTTPContentEncoding::COMPRESS;
            else if (header.ContentEncodingString == "deflate")
                header.ContentEncoding = HTTPContentEncoding::DEFLATE;
            else if (header.ContentEncodingString == "exi")
                header.ContentEncoding = HTTPContentEncoding::EXI;
            else if (header.ContentEncodingString == "gzip")
                header.ContentEncoding = HTTPContentEncoding::GZIP;
            else if (header.ContentEncodingString == "identity")
                header.ContentEncoding = HTTPContentEncoding::IDENTITY;
            else if (header.ContentEncodingString == "pack200-gzip")
                header.ContentEncoding = HTTPContentEncoding::PACK200_GZIP;
            else if (header.ContentEncodingString == "sdch")
                header.ContentEncoding = HTTPContentEncoding::SDCH;
            else if (header.ContentEncodingString == "bzip2")
                header.ContentEncoding = HTTPContentEncoding::BZIP2;
            else if (header.ContentEncodingString == "peerdist")
                header.ContentEncoding = HTTPContentEncoding::PEERDIST;
            else if (header.ContentEncodingString == "lzma")
                header.ContentEncoding = HTTPContentEncoding::LZMA;
            else
                header.ContentEncoding = HTTPContentEncoding::UNKNOWN;
        }
        else if (parts[0] == "Content-Language:") 
        {
            header.ContentLanguage = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentLanguage += parts[j] + " ";
            header.ContentLanguage.Trim();
        }
        else if (parts[0] == "Content-Length:")
        {
            header.ContentLength = parts[1].To<int>(0); 

            header.ContentLengthString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentLengthString += parts[j] + " ";
            header.ContentLengthString.Trim();
        }
        else if (parts[0] == "Content-Location:") 
        {
            header.ContentLocation = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentLocation += parts[j] + " ";
            header.ContentLocation.Trim();
        }
        else if (parts[0] == "Content-MD5:") 
        {
            header.ContentMD5 = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentMD5 += parts[j] + " ";
            header.ContentMD5.Trim();
        }
        else if (parts[0] == "Content-Range:") 
        {
            header.ContentRangeString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ContentRangeString += parts[j] + " ";
            header.ContentRangeString.Trim();
        }
        else if (parts[0] == "Content-Type:") 
        {
            header.ContentType = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.ContentType += parts[j] + " ";
                if (parts[j].SubString(0,8) == "charset=")
                {
                    header.CharsetString = parts[j].SubString(8);
                    header.CharsetString.Trim();
                    header.CharsetString.ToUpper();

                    if (header.CharsetString == "ISO-8859-1")
                        header.Charset = HTTPCharsets::ISO_8859_1;
                    else if (header.CharsetString == "ISO-8859-2")
                        header.Charset = HTTPCharsets::ISO_8859_2;
                    else if (header.CharsetString == "ISO-8859-3")
                        header.Charset = HTTPCharsets::ISO_8859_3;
                    else if (header.CharsetString == "ISO-8859-4")
                        header.Charset = HTTPCharsets::ISO_8859_4;
                    else if (header.CharsetString == "ISO-8859-5")
                        header.Charset = HTTPCharsets::ISO_8859_5;
                    else if (header.CharsetString == "ISO-8859-6")
                        header.Charset = HTTPCharsets::ISO_8859_6;
                    else if (header.CharsetString == "ISO-8859-7")
                        header.Charset = HTTPCharsets::ISO_8859_7;
                    else if (header.CharsetString == "ISO-8859-8")
                        header.Charset = HTTPCharsets::ISO_8859_8;
                    else if (header.CharsetString == "ISO-8859-9")
                        header.Charset = HTTPCharsets::ISO_8859_9;
                    else if (header.CharsetString == "ISO-8859-10")
                        header.Charset = HTTPCharsets::ISO_8859_10;
                    else if (header.CharsetString == "ISO-8859-15")
                        header.Charset = HTTPCharsets::ISO_8859_15;
                    else if (header.CharsetString == "ISO-2022-JP")
                        header.Charset = HTTPCharsets::ISO_2022_JP;
                    else if (header.CharsetString == "ISO-2022-JP-2")
                        header.Charset = HTTPCharsets::ISO_2022_JP_2;
                    else if (header.CharsetString == "ISO-2022-KR")
                        header.Charset = HTTPCharsets::ISO_2022_KR;
                    else if (header.CharsetString == "UTF-8")
                        header.Charset = HTTPCharsets::UTF_8;
                    else if (header.CharsetString == "UTF-16")
                        header.Charset = HTTPCharsets::UTF_16;
                    else
                        header.Charset = HTTPCharsets::UNKNOWN;
                }
                else if (parts[j].FindFirstOf(";") > 0)
                {
                    header.MIME = parts[j].SubString(0,parts[j].FindFirstOf(";"));
                }
            }
            header.ContentType.Trim();
        }
        else if (parts[0] == "Date:") 
        {
            header.Date = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Date += parts[j] + " ";
            header.Date.Trim();
        }
        else if (parts[0] == "ETag:") 
        {
            header.ETag = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ETag += parts[j] + " ";
            header.ETag.Trim();
        }
        else if (parts[0] == "Expires:") 
        {
            header.Expires = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Expires += parts[j] + " ";
            header.Expires.Trim();
        }
        else if (parts[0] == "Last-Modified:") 
        {
            header.LastModified = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.LastModified += parts[j] + " ";
            header.LastModified.Trim();
        }
        else if (parts[0] == "Link:") 
        {
            header.Link = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Link += parts[j] + " ";
            header.Link.Trim();
        }
        else if (parts[0] == "Location:") 
        {
            header.Location = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Location += parts[j] + " ";
            header.Location.Trim();
        }
        else if (parts[0] == "P3P:") 
        {
            header.P3P = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.P3P += parts[j] + " ";
            header.P3P.Trim();
        }
        else if (parts[0] == "Pragma:") 
        {
            header.Pragma = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Pragma += parts[j] + " ";
            header.Pragma.Trim();
        }
        else if (parts[0] == "Proxy-Authenticate:") 
        {
            header.ProxyAuthenticate = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.ProxyAuthenticate += parts[j] + " ";
            header.ProxyAuthenticate.Trim();
        }
        else if (parts[0] == "Refresh:") 
        {
            header.RefreshString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
            {
                header.RefreshString += parts[j] + " ";
                if (parts[j].SubString(0,4) == "url=")
                {
                    header.RefreshUrl = parts[j].SubString(4);
                    header.RefreshUrl.Trim();
                }
                else if (parts[j].FindFirstOf(";") > 0)
                    header.Refresh = parts[j].SubString(0,parts[j].FindFirstOf(";")).To<int>(0);
            }
            header.RefreshString.Trim();
        }
        else if (parts[0] == "Retry-After:") 
        {
            header.RetryAfterString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.RetryAfterString += parts[j] + " ";
            header.RetryAfterString.Trim();

            header.RetryAfter = header.RetryAfterString.To<int>(0);
        }
        else if (parts[0] == "Server:")
        {
            header.Server = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Server += parts[j] + " ";
            header.Server.Trim();
        }
        else if (parts[0] == "Set-Cookie:")
        {
            header.SetCookie = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.SetCookie += parts[j] + " ";
            header.SetCookie.Trim();

            //TODO: Parse Set-Cookie
        }
        else if (parts[0] == "Status:")
        {
            header.Status = parts[1].To<int>(0);

            header.StatusString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.StatusString += parts[j] + " ";
            header.StatusString.Trim();
        }
        else if (parts[0] == "Strict-Transport-Security:")
        {
            header.StrictTransportSecurity = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.StrictTransportSecurity += parts[j] + " ";
            header.StrictTransportSecurity.Trim();
        }
        else if (parts[0] == "Trailer:")
        {
            header.Trailer = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Trailer += parts[j] + " ";
            header.Trailer.Trim();
        }
        else if (parts[0] == "Transfer-Encoding:")
        {
            header.TransferEncodingString = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.TransferEncodingString += parts[j] + " ";
            header.TransferEncodingString.Trim();

            if (header.TransferEncodingString == "chunked")
                header.TransferEncoding = HTTPTransferEncoding::CHUNKED;
            else if (header.TransferEncodingString == "compress")
                header.TransferEncoding = HTTPTransferEncoding::COMPRESS;
            else if (header.TransferEncodingString == "deflate")
                header.TransferEncoding = HTTPTransferEncoding::DEFLATE;
            else if (header.TransferEncodingString == "gzip")
                header.TransferEncoding = HTTPTransferEncoding::GZIP;
            else if (header.TransferEncodingString == "identity")
                header.TransferEncoding = HTTPTransferEncoding::IDENTITY;
            else
                header.TransferEncoding = HTTPTransferEncoding::UNKNOWN;
        }
        else if (parts[0] == "Vary:")
        {
            header.Vary = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Vary += parts[j] + " ";
            header.Vary.Trim();
        }
        else if (parts[0] == "Via:")
        {
            header.Via = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Via += parts[j] + " ";
            header.Via.Trim();
        }
        else if (parts[0] == "Warning:")
        {
            header.Warning = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.Warning += parts[j] + " ";
            header.Warning.Trim();
        }
        else if (parts[0] == "WWW-Authenticate:")
        {
            header.WWWAuthenticate = "";
            for (unsigned int j = 1; j < parts.size(); j++)
                header.WWWAuthenticate += parts[j] + " ";
            header.WWWAuthenticate.Trim();
        }
    }
}

Jatta::String Jatta::Network::HTTPRequest::EncodeString(const char* buffer, int len)
{
    String ret = "";

    switch (header.Charset)
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
                                codePoint += (code-48)*((j == 0) ? 1 : 16*j);
                            if (code >= 65 && code <= 70) //A-F
                                codePoint += (code-55)*((j == 0) ? 1 : 16*j);
                            if (code >= 97 && code <= 102) //a-f
                                codePoint += (code-87)*((j == 0) ? 1 : 16*j);
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
                                codePoint += (code-48)*((j == 0) ? 1 : 16*j);
                            if (code >= 65 && code <= 70) //A-F
                                codePoint += (code-55)*((j == 0) ? 1 : 16*j);
                            if (code >= 97 && code <= 102) //a-f
                                codePoint += (code-87)*((j == 0) ? 1 : 16*j);
                        }

                        ret += Jatta::String::FromCodePoint(codePoint);
                        i += 5;
                    }
                }
                else
                    ret += buffer[i];
            }
        }
        break;

        default:    //Unknown charset, just set the string to the buffer.
            ret.Set(buffer);
            break;
    }
    return ret;
}

Jatta::Network::HTTPRequest::HTTPRequest()
{
    sock = new SocketTCP();
}
Jatta::Network::HTTPRequest::~HTTPRequest()
{
    Close();
    delete sock;
}

void Jatta::Network::HTTPRequest::Http(const String url)
{
    host = url;

    DNS dns;
    std::vector<Jatta::String> lookup = dns.Lookup(url);
    if (lookup.size() == 0)
        return;

    sock->Connect(IPAddress(lookup[0]), 80);
}
void Jatta::Network::HTTPRequest::Connect(const IPAddress& ip, int port)
{
    host = ip.ToString();
    sock->Connect(ip, port);
}

#ifdef OpenSSL_FOUND
void Jatta::Network::HTTPRequest::Https(const String url)
{
    host = url;

    DNS dns;
    std::vector<Jatta::String> lookup = dns.Lookup(url);
    if (lookup.size() == 0)
        return;

    sock->ConnectSSL(IPAddress(lookup[0]), 443);
}
void Jatta::Network::HTTPRequest::ConnectSSL(const IPAddress& ip, int port)
{
    host = ip.ToString();
    sock->ConnectSSL(ip, port);
}
#endif

void Jatta::Network::HTTPRequest::Close()
{
    sock->Close();
}

bool Jatta::Network::HTTPRequest::Request(String req, int timeout)
{
    request = req;
    request += "\n\r\n";

    return PerformRequest(timeout);
}

bool Jatta::Network::HTTPRequest::Get(String page, int timeout)
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

bool Jatta::Network::HTTPRequest::Head(String page, int timeout)
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

bool Jatta::Network::HTTPRequest::Post(String page, Jatta::String content, int timeout)
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

bool Jatta::Network::HTTPRequest::IsConnected()
{
    return sock->IsConnected();
}
Jatta::Network::SocketTCP* Jatta::Network::HTTPRequest::GetSocket()
{
    return sock;
}

Jatta::String Jatta::Network::HTTPRequest::GetRequest()
{
    return request;
}
Jatta::String Jatta::Network::HTTPRequest::GetResponse()
{
    return response;
}
Jatta::Network::Header Jatta::Network::HTTPRequest::GetHeader()
{
    return header;
}
Jatta::String Jatta::Network::HTTPRequest::GetResponseHead()
{
    return responseHead;
}
Jatta::String Jatta::Network::HTTPRequest::GetResponseBody()
{
    return responseBody;
}
