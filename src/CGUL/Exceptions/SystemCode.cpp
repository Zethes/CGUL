// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SystemCode.cpp
 */

// Header
#include "SystemCode.hpp"

_CGUL_EXPORT CGUL::SystemCode::SystemCode() :
    code(0),
    type(TYPE_NONE)
{
}

_CGUL_EXPORT CGUL::SystemCode CGUL::SystemCode::CheckWinApi()
{
    SystemCode code;
    code.type = TYPE_WINAPI;

#   ifdef CGUL_WINDOWS
    code.code = GetLastError();
#   endif

    return code;
}

_CGUL_EXPORT CGUL::SystemCode CGUL::SystemCode::CheckErrno()
{
    SystemCode code;
    code.type = TYPE_ERRNO;

#   ifdef CGUL_LINUX
    code.code = errno;
#   endif

    return code;
}

_CGUL_EXPORT CGUL::SystemCode CGUL::SystemCode::CheckNetwork()
{
    SystemCode code;
    code.type = TYPE_NETWORK;

#   ifdef CGUL_WINDOWS
    code.code = WSAGetLastError();
#   else
    code.code = errno;
#   endif

    return code;
}

_CGUL_EXPORT CGUL::SystemCode CGUL::SystemCode::UseNetwork(int error)
{
    SystemCode code;
    code.type = TYPE_NETWORK;

    code.code = error;

    return code;
}

_CGUL_EXPORT CGUL::SystemCode CGUL::SystemCode::UseSSL(int error)
{
    SystemCode code;
    code.type = TYPE_SSL;

    code.code = error;

    return code;
}

_CGUL_EXPORT CGUL::SystemCode CGUL::SystemCode::UseAddrInfo(int error)
{
    SystemCode code;
    code.type = TYPE_ADDR_INFO;

    code.code = error;

    return code;
}

_CGUL_EXPORT CGUL::String CGUL::SystemCode::GetInfo() const
{
    if (type == TYPE_NONE)
    {
        return U8("None");
    }

    CGUL::String info;
    switch (type)
    {
        case TYPE_WINAPI:
            info += U8("WinAPI");
            break;
        case TYPE_ERRNO:
            info += U8("Errno");
            break;
        case TYPE_NETWORK:
            info += U8("Network");
            break;
        case TYPE_SSL:
            info += U8("SSL");
            break;
        case TYPE_ADDR_INFO:
            info += U8("Address Info");
            break;
    }
    info += U8(" Error ") + String::From(code);

    CGUL::String reason;

    if (type == TYPE_WINAPI)
    {
#       ifdef CGUL_WINDOWS
#       endif
    }

    if (type == TYPE_NETWORK || type == TYPE_ERRNO)
    {
#       ifdef CGUL_LINUX
        static struct { int value; const char* str; } errnoList[] =
        {
            { E2BIG,           "E2BIG" },
            { EACCES,          "EACCES" },
            { EADDRINUSE,      "EADDRINUSE" },
            { EADDRNOTAVAIL,   "EADDRNOTAVAIL" },
            { EAFNOSUPPORT,    "EAFNOSUPPORT" },
            { EAGAIN,          "EAGAIN" },
            { EALREADY,        "EALREADY" },
            { EBADE,           "EBADE" },
            { EBADF,           "EBADF" },
            { EBADFD,          "EBADFD" },
            { EBADMSG,         "EBADMSG" },
            { EBADR,           "EBADR" },
            { EBADRQC,         "EBADRQC" },
            { EBADSLT,         "EBADSLT" },
            { EBUSY,           "EBUSY" },
            { ECANCELED,       "ECANCELED" },
            { ECHILD,          "ECHILD" },
            { ECHRNG,          "ECHRNG" },
            { ECOMM,           "ECOMM" },
            { ECONNABORTED,    "ECONNABORTED" },
            { ECONNREFUSED,    "ECONNREFUSED" },
            { ECONNRESET,      "ECONNRESET" },
            { EDEADLK,         "EDEADLK" },
            { EDEADLOCK,       "EDEADLOCK" },
            { EDESTADDRREQ,    "EDESTADDRREQ" },
            { EDOM,            "EDOM" },
            { EDQUOT,          "EDQUOT" },
            { EEXIST,          "EEXIST" },
            { EFAULT,          "EFAULT" },
            { EFBIG,           "EFBIG" },
            { EHOSTDOWN,       "EHOSTDOWN" },
            { EHOSTUNREACH,    "EHOSTUNREACH" },
            { EIDRM,           "EIDRM" },
            { EILSEQ,          "EILSEQ" },
            { EINPROGRESS,     "EINPROGRESS" },
            { EINTR,           "EINTR" },
            { EINVAL,          "EINVAL" },
            { EIO,             "EIO" },
            { EISCONN,         "EISCONN" },
            { EISDIR,          "EISDIR" },
            { EISNAM,          "EISNAM" },
            { EKEYEXPIRED,     "EKEYEXPIRED" },
            { EKEYREJECTED,    "EKEYREJECTED" },
            { EKEYREVOKED,     "EKEYREVOKED" },
            { EL2HLT,          "EL2HLT" },
            { EL2NSYNC,        "EL2NSYNC" },
            { EL3HLT,          "EL3HLT" },
            { EL3RST,          "EL3RST" },
            { ELIBACC,         "ELIBACC" },
            { ELIBBAD,         "ELIBBAD" },
            { ELIBMAX,         "ELIBMAX" },
            { ELIBSCN,         "ELIBSCN" },
            { ELIBEXEC,        "ELIBEXEC" },
            { ELOOP,           "ELOOP" },
            { EMEDIUMTYPE,     "EMEDIUMTYPE" },
            { EMFILE,          "EMFILE" },
            { EMLINK,          "EMLINK" },
            { EMSGSIZE,        "EMSGSIZE" },
            { EMULTIHOP,       "EMULTIHOP" },
            { ENAMETOOLONG,    "ENAMETOOLONG" },
            { ENETDOWN,        "ENETDOWN" },
            { ENETRESET,       "ENETRESET" },
            { ENETUNREACH,     "ENETUNREACH" },
            { ENFILE,          "ENFILE" },
            { ENOBUFS,         "ENOBUFS" },
            { ENODATA,         "ENODATA" },
            { ENODEV,          "ENODEV" },
            { ENOENT,          "ENOENT" },
            { ENOEXEC,         "ENOEXEC" },
            { ENOKEY,          "ENOKEY" },
            { ENOLCK,          "ENOLCK" },
            { ENOLINK,         "ENOLINK" },
            { ENOMEDIUM,       "ENOMEDIUM" },
            { ENOMEM,          "ENOMEM" },
            { ENOMSG,          "ENOMSG" },
            { ENONET,          "ENONET" },
            { ENOPKG,          "ENOPKG" },
            { ENOPROTOOPT,     "ENOPROTOOPT" },
            { ENOSPC,          "ENOSPC" },
            { ENOSR,           "ENOSR" },
            { ENOSTR,          "ENOSTR" },
            { ENOSYS,          "ENOSYS" },
            { ENOTBLK,         "ENOTBLK" },
            { ENOTCONN,        "ENOTCONN" },
            { ENOTDIR,         "ENOTDIR" },
            { ENOTEMPTY,       "ENOTEMPTY" },
            { ENOTSOCK,        "ENOTSOCK" },
            { ENOTSUP,         "ENOTSUP" },
            { ENOTTY,          "ENOTTY" },
            { ENOTUNIQ,        "ENOTUNIQ" },
            { ENXIO,           "ENXIO" },
            { EOPNOTSUPP,      "EOPNOTSUPP" },
            { EOVERFLOW,       "EOVERFLOW" },
            { EPERM,           "EPERM" },
            { EPFNOSUPPORT,    "EPFNOSUPPORT" },
            { EPIPE,           "EPIPE" },
            { EPROTO,          "EPROTO" },
            { EPROTONOSUPPORT, "EPROTONOSUPPORT" },
            { EPROTOTYPE,      "EPROTOTYPE" },
            { ERANGE,          "ERANGE" },
            { EREMCHG,         "EREMCHG" },
            { EREMOTE,         "EREMOTE" },
            { EREMOTEIO,       "EREMOTEIO" },
            { ERESTART,        "ERESTART" },
            { EROFS,           "EROFS" },
            { ESHUTDOWN,       "ESHUTDOWN" },
            { ESPIPE,          "ESPIPE" },
            { ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT" },
            { ESRCH,           "ESRCH" },
            { ESTALE,          "ESTALE" },
            { ESTRPIPE,        "ESTRPIPE" },
            { ETIME,           "ETIME" },
            { ETIMEDOUT,       "ETIMEDOUT" },
            { ETXTBSY,         "ETXTBSY" },
            { EUCLEAN,         "EUCLEAN" },
            { EUNATCH,         "EUNATCH" },
            { EUSERS,          "EUSERS" },
            { EWOULDBLOCK,     "EWOULDBLOCK" },
            { EXDEV,           "EXDEV" },
            { EXFULL,          "EXFULL" }
        };

        for (unsigned int i = 0; i < sizeof(errnoList) / (sizeof(int) + sizeof(const char*)); i++)
        {
            if (code == errnoList[i].value)
            {
                // Some operating systems shared values for errno error enumerations. The below
                // code will create a list of errno enums that were equal to the error code.
                if (reason == U8(""))
                {
                    reason = errnoList[i].str;
                }
                else
                {
                    reason += U8(", ") + errnoList[i].str;
                }
            }
        }
#       endif
    }

    if (type == TYPE_NETWORK)
    {
#       ifdef CGUL_WINDOWS
#       endif
    }

    if (type == TYPE_ADDR_INFO)
    {
        switch (code)
        {
#           ifndef CGUL_WINDOWS
            case EAI_ADDRFAMILY: reason = "EAI_ADDRFAMILY"; break;
#           endif
            case EAI_AGAIN:      reason = "EAI_AGAIN";      break;
            case EAI_BADFLAGS:   reason = "EAI_BADFLAGS";   break;
            case EAI_FAIL:       reason = "EAI_FAIL";       break;
            case EAI_FAMILY:     reason = "EAI_FAMILY";     break;
            case EAI_MEMORY:     reason = "EAI_MEMORY";     break;
#           ifndef CGUL_WINDOWS
            case EAI_NODATA:     reason = "EAI_NODATA";     break;
#           endif
            case EAI_NONAME:     reason = "EAI_NONAME";     break;
            case EAI_SERVICE:    reason = "EAI_SERVICE";    break;
            case EAI_SOCKTYPE:   reason = "EAI_SOCKTYPE";   break;
#           ifndef CGUL_WINDOWS
            case EAI_SYSTEM:     reason = "EAI_SYSTEM";     break;
#           endif
        }
    }

    if (!reason.IsEmpty())
    {
        info += U8(" (") + reason + U8(")");
    }

    return info;
}
