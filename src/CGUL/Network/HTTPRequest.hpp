// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HTTPRequest.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Network/IPAddress.hpp"
#include "../Network/SocketTCP.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Network
    {
        /** @struct Header HTTPRequest.hpp <CGUL/Network/HTTPRequest.hpp>
         *  @brief A structure containing the response header for HTTPRequests
         */
        struct Header
        {
            String accessControlAllowOrigin;
            String acceptRanges;
            SIntN age;
            String ageString;
            String allow;
            String cacheControl;
            SIntN charset;
            String charsetString;
            SIntN connection;
            String connectionString;
            String contentDisposition;
            SIntN contentEncoding;
            String contentEncodingString;
            String contentLanguage;
            UIntN contentLength;
            String contentLengthString;
            String contentLocation;
            String contentMD5;
            SIntN contentRangeMin, contentRangeMax;
            String contentRangeString;
            String contentType;
            String date;
            String eTag;
            String expires;
            String lastModified;
            String link;
            String location;
            String mime;
            String p3p;
            String pragma;
            String proxyAuthenticate;
            SIntN refresh;
            String refreshString;
            String refreshUrl;
            SIntN retryAfter;
            String retryAfterString;
            String server;
            String setCookie;
            String setCookieID;
            SIntN setCookieValue;
            SIntN setCookieVersion;
            SIntN status;
            String statusString;
            String strictTransportSecurity;
            String trailer;
            SIntN transferEncoding;
            String transferEncodingString;
            String vary;
            String via;
            String warning;
            String wwwAuthenticate;

            Header();
        };

        /** @class HTTPRequest HTTPRequest.hpp <CGUL/Network/HTTPRequest.hpp>
         *  @brief A class to connect to webpages and request data.
         */
        class HTTPRequest
        {
            SocketTCP* sock;
            String host;
            String request, response, responseHead, responseBody;
            Header header;

            HTTPRequest(const HTTPRequest& copy);

            bool PerformRequest(UInt32 timeout);
            void ParseResponseHead();
            String EncodeString(const char* buffer, UIntN len);
        public:
            HTTPRequest();
            ~HTTPRequest();

            void Http(const String& url);
            void Connect(const IPAddress& ip, int port);

#           ifdef OpenSSL_FOUND
            void Https(const String& url);
            void ConnectSSL(const IPAddress& ip, int port);
#           endif

            void Close();

            bool Request(String request, UInt32 timeout = 0);
            bool Get(String page, UInt32 timeout = 0);
            bool Head(String page, UInt32 timeout = 0);
            bool Post(String page, String content, UInt32 timeout = 0);
            //TODO: PUT, DELETE, TRACE, OPTIONS, CONNECT, PATCH

            bool IsConnected();
            SocketTCP* GetSocket();

            String GetRequest();
            String GetResponse();
            Header GetHeader();
            String GetResponseHead();
            String GetResponseBody();
        };
    }
}

#include "../External/Undefines.hpp"
