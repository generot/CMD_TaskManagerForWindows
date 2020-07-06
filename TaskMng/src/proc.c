#include "../include/tools.h"

void ListAllProcesses(void) {
    PROCESSENTRY32W pEntry;
    pEntry.dwSize = sizeof(PROCESSENTRY32W);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    Process32FirstW(snapshot, &pEntry);
    wprintf(L"%ls\n", pEntry.szExeFile);

    while(Process32NextW(snapshot, &pEntry))
         wprintf(L"%ls\n", pEntry.szExeFile);

    CloseHandle(snapshot);
}

bool KillProcessById(HANDLE hnd, DWORD id) {
    HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, id);
    if(proc) {
        if(!TerminateProcess(proc, EXIT_SUCCESS)){
            ISSUE_ERROR(hnd, "Process could not be terminated.\n");
            return false;
        }
    }
    else {
        ISSUE_ERROR(hnd, "Process could not be accessed.\n");
        return false;
    }

    return true;
}

DWORD GetProcID(LPSTR name) {
    size_t sz = strlen(name)+1;
    WCHAR nm[sz];

    mbstowcs(nm, name, sz);
    if(nm[sz-2] == '\n')
        nm[sz-2] = '\0';

    nm[sz-1] = '\0';

    PROCESSENTRY32W pEntry;
    pEntry.dwSize = sizeof(PROCESSENTRY32W);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    Process32FirstW(snapshot, &pEntry);
    if(wcsncmp(nm, pEntry.szExeFile, sz) == 0)
        return pEntry.th32ProcessID;

    while(Process32NextW(snapshot, &pEntry))
         if(wcsncmp(nm, pEntry.szExeFile, sz) == 0)
            return pEntry.th32ProcessID;

    CloseHandle(snapshot);
    return 0;
}