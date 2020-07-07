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
        "help",
        "cls"
    };

    size_t cmdSz = sizeof(cmds)/sizeof(char*);

    while(true) {
        char userResponse[MAX_STR] = {0}, *token_immutable = NULL, *token = NULL;

        //We use this variable to determine how many times a multiple input instruction(getpid, killp)
        //can be tokenized before we reach \0. If it stays at 0, we didn't use the instruction correctly,
        //therefore we're issued an error message
        int execs = 0;
        
        fgets(userResponse, MAX_STR-1, stdin);
        token_immutable = strtok(userResponse, " ");
        
        for(int i = 0; i < cmdSz; i++)
            if(!strncmp(token_immutable, cmds[i], strlen(cmds[i])))
                switch(i) {
                case 0: ListAllProcesses(); break;
                case 1: {
                    do {
                        token = strtok(NULL, " ");
                        if(!token && !execs) {
                            ISSUE_ERROR(cons, "Usage: killp <process_id>...\n");
                            break;
                        } else if(token) {
                            DWORD id = (DWORD)atol(token);
                            KillProcessById(cons, id); 
                            execs++;
                        }
                    } while(token);

                    break;
                }
                case 2: {
                    //The string is tokenized as "getpid", "<token>\n" if we enter one process
                    //so we ignore '\n' by setting it to '\0' in GetProcID();
                    int tknAmount = 1;

                    do {
                        token = strtok(NULL, " ");
                        if(!token && !execs) {
                            ISSUE_ERROR(cons, "Usage: getpid <process_name>...\n");
                            break;
                        } else if(token){ 
                            printf("ID #%d: %li\n", tknAmount++, GetProcID(token));
                            execs++;
                        }
                    } while(token);

                    break;
                }
                case 3: CloseHandle(cons); exit(EXIT_SUCCESS); break;
                case 4: PrintWithDelay(cons, HELP_MSG, COL_MAGENTA, 5); break;
                case 5: if(!ClearConsole(cons)) ISSUE_ERROR(cons, "Could not clear the console.\n"); break;
                }
    }

    CloseHandle(cons);
    return 0;
}