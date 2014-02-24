#include <Windows.h>

DWORD WINAPI MyThread(LPVOID lpParam)
{
}

int main()
{
    HANDLE thread = CreateThread(0, 0, MyThread, NULL, 0, NULL);
    WaitForSingleObject(thread, INFINITE);
    TerminateThread(thread, 0);
}
