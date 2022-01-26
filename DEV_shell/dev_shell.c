#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define COMM_LEN 100

/* Get_command: get command from the user 
 * cut extra white simbols (' ', '\n', '\t')
 * returns len of gotten command
 */
int Get_command(char *command, int n);


int main()
{
    char command[COMM_LEN];
    int len=0;

    while (1)
    {
        len = Get_command(command, COMM_LEN);

        putchar('\n');

        if (len == -1) {                                                    // EOF
            printf("Tic-Tac[MENU]: EOF found. Exiting...\n");
            return -1;
        } else if (len == 0) {                                              // Empty command
            continue;
        } else if (!strcmp(command, "q")) {        // Exit command
            printf("Tic-Tac[MENU]: exit command found. Exiting...\n");
            break;

        } else if (!strcmp(command, "h") || !strcmp(command, "help")) {     // Help command

            printf("HELP LIST: here you can see all commands like: \n");
            printf("\t[command]decoding --> DO\n\n");

            printf("[q]uite --> EXIT\n");
            
            printf("[h]elp  --> HELP\n");

            printf("[*]     --> SOON\n");
            printf("[/]     --> SOON\n");

            printf("[x]     --> SOON\n");
            printf("[o]     --> SOON\n");


            printf("\n\n");

//        } else if () {
//        } else if () {
 
        } else {                                                            // Unknown command
           printf("Tic-Tac[MENU]: unknown command. Try [H]elp to get command list\n");
        }
    }

    return 0;
}

int Get_command(char *command, int limit)
{
    
    char simbol;
    int len=0;

    printf("[~] ");
    while (len<limit && (simbol = getchar()) != '\n' && simbol != EOF)
    {
        // replace tabs by space
        if (simbol == '\t')
            simbol = ' ';

        /* ignore white simbol IF
         * it's the first OR 
         * the last simbol was also white 
         */
        if ( isspace(simbol) && (len==0 || isspace(command[len-1])) ) 
            ; 
        else {
            command[len]=simbol;
            len++;
        }
    }

    // exit if EOF
    if (simbol==EOF)
        return -1;

    // if last simbol is space: replace it by '\0'
    if (isspace(command[len-1]))
        len--;

    command[len] = '\0';

    return len; 
}

