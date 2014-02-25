#if !defined(_WIN32_WINNT)
#   define _WIN32_WINNT 0x0600
#endif

#if !defined(WINVER)
#   define WINVER 0x0600
#endif

#include <Windows.h>

DWORD WINAPI MyThread(LPVOID lpParam)
{
    return 0;
}

int main()
{
    HANDLE thread = CreateThread(0, 0, MyThread, NULL, 0, NULL);
    WaitForSingleObject(thread, INFINITE);
    TerminateThread(thread, 0);

    CONDITION_VARIABLE a;
    CRITICAL_SECTION b;
}
