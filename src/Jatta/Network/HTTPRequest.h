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
            Jatta::String AccessControlAllowOrigin;
            Jatta::String AcceptRanges;
            int Age;
            Jatta::String AgeString;
            Jatta::String Allow;
            Jatta::String CacheControl;
            int Charset;
            Jatta::String CharsetString;
            int Connection;
            Jatta::String ConnectionString;
            Jatta::String ContentDisposition;
            int ContentEncoding;
            Jatta::String ContentEncodingString;
            Jatta::String ContentLanguage;
            int ContentLength;
            Jatta::String ContentLengthString;
            Jatta::String ContentLocation;
            Jatta::String ContentMD5;
            int ContentRangeMin,ContentRangeMax;
            Jatta::String ContentRangeString;
            Jatta::String ContentType;
            Jatta::String Date;
            Jatta::String ETag;
            Jatta::String Expires;
            Jatta::String LastModified;
            Jatta::String Link;
            Jatta::String Location;
            Jatta::String MIME;
            Jatta::String P3P;
            Jatta::String Pragma;
            Jatta::String ProxyAuthenticate;
            int Refresh;
            Jatta::String RefreshString;
            Jatta::String RefreshUrl;
            int RetryAfter;
            Jatta::String RetryAfterString;
            Jatta::String Server;
            Jatta::String SetCookie;
            Jatta::String SetCookieID;
            int SetCookieValue;
            int SetCookieVersion;
            int Status;
            Jatta::String StatusString;
            Jatta::String StrictTransportSecurity;
            Jatta::String Trailer;
            int TransferEncoding;
            Jatta::String TransferEncodingString;
            Jatta::String Vary;
            Jatta::String Via;
            Jatta::String Warning;
            Jatta::String WWWAuthenticate;
        };

        /** @class HTTPRequest HTTPRequest.h <Base/Network/HTTPRequest.h>
         *  @brief A class to connect to webpages and request data.
         */
        class HTTPRequest
        {
            SocketTCP* sock;
            Jatta::String host;
            Jatta::String request, response, responseHead, responseBody;
            Header header;

            bool PerformRequest(int timeout);
            void ParseResponseHead();
            Jatta::String EncodeString(const char* buffer, int len);
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
            bool Post(String page, Jatta::String content, int timeout = 0);
            //TODO: PUT, DELETE, TRACE, OPTIONS, CONNECT, PATCH

            bool IsConnected();
            SocketTCP* GetSocket();

            Jatta::String GetRequest();
            Jatta::String GetResponse();
            Header GetHeader();
            Jatta::String GetResponseHead();
            Jatta::String GetResponseBody();
            
        };
    }
}

#include "../External/Undefines.h"
