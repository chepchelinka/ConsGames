#include <stdio.h>
#include <string.h>

#include "game/game.h"

int main()
{
    char command[COMMAND_LEN];
    int len=0;

    printf("Welcome to the Tic-Tac.\n");
    printf("Version: 2.0\n\n");


    while (1)
    {
        printf("    [~] ");
        len = Get_command(command);

        putchar('\n');

        if (len == -1) {                                                    // EOF
            printf("Tic-Tac[~]: EOF found. Exiting...\n");
            return -1;
        } else if (len == 0) {                                              // Empty command
            continue;
        } else if (!strcmp(command, "q")) {                                 // Exit command
            printf("Tic-Tac[~]: exit command found. Exiting...\n");
            break;

        } else if (!strcmp(command, "h") || !strcmp(command, "help")) {     // Help command

            printf("HELP LIST: here you can see all commands like: \n");
            printf("\t[command]decoding --> DO\n\n");

            printf("[q]uite --> EXIT\n");
            printf("[h]elp  --> HELP LIST\n");
            printf("[S]tart --> START THE GAME\n");

            printf("[/]     --> SOON\n");
            printf("[x]     --> SOON\n");
            printf("[o]     --> SOON\n");


       } else if (!strcmp(command, "s") || !strcmp(command, "start")) {

           Game_loop();


//        } else if () {
//        } else if () {
//        } else if () {
 
        } else {                                                            // Unknown command
           printf("Tic-Tac[~]: unknown command: %s. \nTry [H]elp to get command list.\n", command);
        }

        putchar('\n');

    }

    return 0;
}


