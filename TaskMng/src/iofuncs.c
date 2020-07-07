#include "../include/tools.h"

bool PrintWithDelay(HANDLE hnd, char *str, colour col, int delay) {
    char ch;
    SetConsoleTextAttribute(hnd, col);

    if(!str) return false;

    while((ch = *str++)) {
        putchar(ch);
        Sleep(delay);
    }

    SetConsoleTextAttribute(hnd, COL_YELLOW);
    return true;
}

bool ClearConsole(HANDLE hnd) {
    CONSOLE_SCREEN_BUFFER_INFO buffInfo;
    if(!GetConsoleScreenBufferInfo(hnd, &buffInfo))
        return false;

    DWORD dwrd;
    size_t sz = buffInfo.dwSize.X * buffInfo.dwSize.Y;
    char buffer[sz];

    memset(buffer, ' ', sz);
    if(!WriteConsoleA(hnd, buffer, sz, &dwrd, NULL))
        return false;

    SetConsoleCursorPosition(hnd, (COORD){0, 0});
    return true;
}