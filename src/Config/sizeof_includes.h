//////////////////////////////////////////////////
// windows.h                                    //
//////////////////////////////////////////////////
// This is hacky, but we do other checks to
// determine if we can actually use the types
// we're looking up the sizes for.

#if defined(_WIN32_WINNT)
#    undef _WIN32_WINNT
#endif

#if defined(WINVER)
#    undef WINVER
#endif

#define _WIN32_WINNT 0x0600
#define WINVER 0x0600

#include <windows.h>
