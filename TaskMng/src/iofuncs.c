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