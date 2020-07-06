#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <TlHelp32.h>

#define MAX_STR 200
#define ISSUE_ERROR(handle, x) PrintWithDelay((handle), (x), COL_RED, 5)
#define WELCOME_MSG "Command Line Task Manager(CLTM/TMAN) v0.1 - Type \"help\" for more details\n"
#define HELP_MSG "showp - Show all processes\nkillp <id/ids> - Terminate (a) process(es)\ngetpid <name/names> - Get (a) process(es)' name(s)\nexit - Exit the Task Manager\nhelp - Display this menu\n"

typedef enum {false, true} bool;
typedef enum {
    COL_GREEN = 10,
    COL_YELLOW = 6,
    COL_GRAY = 7,
    COL_RED = 12,
    COL_MAGENTA = 5
} colour;

#ifdef __cplusplus
extern "C" {
#endif

void ListAllProcesses(void);

bool KillProcessById(HANDLE hnd, DWORD id);
DWORD GetProcID(LPSTR name);

bool PrintWithDelay(HANDLE hnd, char *str, colour col, int delay);

#ifdef __cplusplus
}
#endif

#endif