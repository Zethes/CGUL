// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HTTPEnums.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Network
    {
        namespace HTTPCacheControls
        {
            enum
            {
                UNKNOWN,
                NO_CACHE,
                NO_STORAGE,
                MAX_AGE,
                NAX_STALE,
                MIN_FRESH,
                NO_TRANSFORM,
                ONLY_IF_CACHED,
                CACHE_EXTENSION,
            };
        }

        namespace HTTPCharsets
        {
            enum
            {
                UNKNOWN = 0,
                ISO_8859_1,
                ISO_8859_2,
                ISO_8859_3,
                ISO_8859_4,
                ISO_8859_5,
                ISO_8859_6,
                ISO_8859_7,
                ISO_8859_8,
                ISO_8859_9,
                ISO_8859_10,
                ISO_8859_15 = 15,
                ISO_2022_JP,
                ISO_2022_JP_2,
                ISO_2022_KR,
                UTF_8,
                UTF_16,
            };
        }

        namespace HTTPConnections
        {
            enum
            {
                UNKNOWN,
                KEEP_ALIVE,
                CLOSE,
            };
        }

        namespace HTTPContentEncoding
        {
            enum
            {
                UNKNOWN,
                COMPRESS,
                DEFLATE,
                EXI,
                GZIP,
                IDENTITY,
                PACK200_GZIP,
                SDCH,
                BZIP2,
                PEERDIST,
                LZMA,
            };
        }

        namespace HTTPStatusCodes
        {
            enum
            {
                UNKNOWN,
                CONTINUE = 100,
                SWITCHING_PROTOCOLS,
                PROCESSING,
                OK = 200,
                CREATED,
                ACCEPTED,
                NON_AUTHORITATIVE_INFORMATION,
                NO_CONTENT,
                RESET_CONTENT,
                PARTIAL_CONTENT,
                MULTI_STATUS,
                IM_USED = 226,
                MULTIPLE_CHOICES = 300,
                MOVED_PERMANENTLY,
                FOUND,
                SEE_OTHER,
                NOT_MODIFIED,
                USE_PROXY,
                TEMPORARY_REDIRECT = 307,
                BAD_REQUEST = 400,
                UNAUTHORIZED,
                PAYMENT_REQUIRED,
                FORBIDDEN,
                NOT_FOUND,
                METHOD_NOT_ALLOWED,
                NOT_ACCEPTABLE,
                PROXY_AUTHENTICATION_REQUIRED,
                REQUEST_TIMEOUT,
                CONFLICT,
                GONE,
                LENGTH_REQUIRED,
                PRECONDITION_FAILED,
                REQUEST_ENTITY_TOO_LARGE,
                REQUEST_URI_TOO_LONG,
                UNSUPPORTED_MEDIA_TYPE,
                REQUESTED_RANGE_NOT_SATISFIABLE,
                EXPECTION_FAILED,
                UNPROCESSABLE_ENTITY = 422,
                LOCKED,
                FAILED_DEPENDENCY,
                UPGRADE_REQUIRED = 426,
                INTERNAL_SERVER_ERROR = 500,
                NOT_IMPLEMENTED,
                BAD_GATEWAY,
                SERVUCE_UNAVAILABLE,
                GATEWAY_TIMEOUT,
                HTTP_VERSION_NOT_SUPPORTED,
                INSUFFICIENT_sTORAGE = 507,
                NOT_EXTENDED = 510,
            };
        }

        namespace HTTPTransferEncoding
        {
            enum
            {
                UNKNOWN,
                CONTENT_LENGTH,
                CHUNKED,
                COMPRESS,
                DEFLATE,
                GZIP,
                IDENTITY,
            };
        }
    }
}

#include "../External/Undefines.hpp"
