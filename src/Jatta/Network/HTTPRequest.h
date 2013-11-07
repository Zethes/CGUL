/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Network/IPAddress.h"
 #include "../Network/SocketTCP.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Network
    {
        /** @struct Header HTTPRequest.h <Base/Network/HTTPRequest.h>
         *  @brief A structure containing the response header for HTTPRequests
         */
        struct Header
        {
            String accessControlAllowOrigin;
            String acceptRanges;
            int age;
            String ageString;
            String allow;
            String cacheControl;
            int charset;
            String charsetString;
            int connection;
            String connectionString;
            String contentDisposition;
            int contentEncoding;
            String contentEncodingString;
            String contentLanguage;
            int contentLength;
            String contentLengthString;
            String contentLocation;
            String contentMD5;
            int contentRangeMin, contentRangeMax;
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
            int refresh;
            String refreshString;
            String refreshUrl;
            int retryAfter;
            String retryAfterString;
            String server;
            String setCookie;
            String setCookieID;
            int setCookieValue;
            int setCookieVersion;
            int status;
            String statusString;
            String strictTransportSecurity;
            String trailer;
            int transferEncoding;
            String transferEncodingString;
            String vary;
            String via;
            String warning;
            String wwwAuthenticate;
        };

        /** @class HTTPRequest HTTPRequest.h <Base/Network/HTTPRequest.h>
         *  @brief A class to connect to webpages and request data.
         */
        class HTTPRequest
        {
            SocketTCP* sock;
            String host;
            String request, response, responseHead, responseBody;
            Header header;

            bool PerformRequest(int timeout);
            void ParseResponseHead();
            String EncodeString(const char* buffer, int len);
        public:
            HTTPRequest();
            ~HTTPRequest();

            void Http(const String url);
            void Connect(const IPAddress& ip, int port);

            #ifdef OpenSSL_FOUND
            void Https(const String url);
            void ConnectSSL(const IPAddress& ip, int port);
            #endif

            void Close();

            bool Request(String request, int timeout = 0);
            bool Get(String page, int timeout = 0);
            bool Head(String page, int timeout = 0);
            bool Post(String page, String content, int timeout = 0);
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

#include "../External/Undefines.h"
