#include "../include/tools.h"

int main(void) {
    HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(cons, COL_YELLOW);

    PrintWithDelay(cons, WELCOME_MSG, COL_GREEN, 5);

    char *cmds[] = {
        "showp",
        "killp",
        "getpid",
        "exit",
        "help"
    };

    size_t cmdSz = sizeof(cmds)/sizeof(char*);

    while(true) {
        char userResponse[MAX_STR] = {0}, *token = NULL;
        
        fgets(userResponse, MAX_STR-1, stdin);
        
        for(int i = 0; i < cmdSz; i++)
            if(!strncmp(userResponse, cmds[i], strlen(cmds[i])))
                switch(i) {
                case 0: ListAllProcesses(); break;
                case 1: {
                    token = strtok(userResponse, " ");
                    while((token = strtok(NULL, " "))){
                        DWORD id = (DWORD)atol(token);
                        KillProcessById(cons, id); 
                    }
                    break;
                }
                case 2: {
                    //The string is tokenized as "getpid", "<token>\n" if we enter one process
                    //so we ignore '\n' by setting it to '\0' in GetProcID();
                    token = strtok(userResponse, " ");
                    int tknAmount = 1;

                    while((token = strtok(NULL, " ")))
                        printf("ID #%d: %li\n", tknAmount++, GetProcID(token));

                    break;
                }
                case 3: exit(EXIT_SUCCESS); break;
                case 4: PrintWithDelay(cons, HELP_MSG, COL_MAGENTA, 5); break;
                }
    }

    CloseHandle(cons);
    return 0;
}