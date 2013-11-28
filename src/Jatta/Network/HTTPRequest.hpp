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
            SInt age;
            String ageString;
            String allow;
            String cacheControl;
            SInt charset;
            String charsetString;
            SInt connection;
            String connectionString;
            String contentDisposition;
            SInt contentEncoding;
            String contentEncodingString;
            String contentLanguage;
            UInt contentLength;
            String contentLengthString;
            String contentLocation;
            String contentMD5;
            SInt contentRangeMin, contentRangeMax;
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
            SInt refresh;
            String refreshString;
            String refreshUrl;
            SInt retryAfter;
            String retryAfterString;
            String server;
            String setCookie;
            String setCookieID;
            SInt setCookieValue;
            SInt setCookieVersion;
            SInt status;
            String statusString;
            String strictTransportSecurity;
            String trailer;
            SInt transferEncoding;
            String transferEncodingString;
            String vary;
            String via;
            String warning;
            String wwwAuthenticate;

            Header();
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

            HTTPRequest(const HTTPRequest& copy);

            bool PerformRequest(UInt32 timeout);
            void ParseResponseHead();
            String EncodeString(const char* buffer, UInt len);
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

#include "../External/Undefines.h"
