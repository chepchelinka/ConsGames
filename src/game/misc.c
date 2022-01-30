#include <stdio.h> 
#include <stdlib.h> // exit
#include <ctype.h>
#include <string.h> // strcmp

#include "game.h"

/* Get_command: get command from the user.
 * Doesn't print invite.
 * Cut extra white simbols (' ', '\n', '\t').
 * Ignoring case.
 * Returns len of gotten command.
 */
int Get_command(char *command)
{
    
    char simbol;
    int len=0;

    while (len<COMMAND_LEN && (simbol = getchar()) != '\n' && simbol != EOF)
    {
        // replace tabs by space
        if (simbol == '\t')
            simbol = ' ';

        /* ignore white simbol 
         *      IF it's the first OR 
         *      IF the last simbol was also white 
         */
        if ( isspace(simbol) && (len==0 || isspace(command[len-1])) ) 
            ; 
        else {
            command[len] = tolower(simbol);
            len++;
        }
    }

    // if command is to long
    if (len==COMMAND_LEN) 
       printf("Tic-Tac[~]: command is too long. You can have a problems\n");
    

    // drop program if EOF
    if (simbol==EOF)
        return -1;

    // if last simbol is space: replace it by '\0'
    if (isspace(command[len-1]))
        len--;

    command[len] = '\0';

    return len; 
}

/* Get_move: get coordinats from user
 * using in src/game/game.c Game_loop
 * use Get_command if user entered not coordinats
 */
struct Move Get_move(int **matrix)
{
    int row, col;
    int status;

    struct Move move;

    printf("Enter coordinats as: ROW:COL (2;1) \nTo get list of avalible commands enter [H]elp \n    [S] ");

    while ( (status = scanf("%d;%d", &row, &col)) != 2 ||
            row < 1 || row > SIZE  ||
            col < 1 || col > SIZE  ||

            matrix[row-1][col-1] != FREE
            ) 
    {

        if (status != 2) {							// string was entered

            int len=0;
            char command[COMMAND_LEN];

            len = Get_command(command);

            if (len==0)
                ;
            else if (len==-1) {
                printf("Tic-Tac[S]: EOF found. Exiting...");
                exit(-1);
            } else if (!strcmp(command, "h") || !strcmp(command, "h")) {
                printf("\n\nHELP LIST: here you can see all commands like: \n");
                printf("\t[command]decoding --> DO\n\n");
                printf("[~]     --> TO THE MAIN MENU\n");
                printf("[H]elp  --> HELP LIST\n");
                printf("[+]     --> SOON\n");
            } else if (!strcmp(command, "~")) {

                printf("Tic-Tac[S]: going to the main menu.\n");

                // do break because values in move (struct) are nulls
                break;
            }
            else {
                printf("Tic-Tac[S]: coordinats must be integers in range (1 -> %d). \nTo get list of avalible commands enter [H]elp\n\n", SIZE);
            }

        } else if (row < 1 || row > SIZE || col < 1 || col > SIZE)  {           // indices out 
            printf("Tic-Tac[S]: coordinats must be integers in range (1 -> %d)\n\n", SIZE);

        } else if (matrix[row-1][col-1] != FREE) {	                        // cell is already used
            printf("Tic-Tac[S]: this cell is already used. Try to get anouther one");
        }

        printf("Enter coordinats as: ROW:COL (2;1).\n\n    [S] ");
    }
    
    move.row = row - 1;
    move.col = col - 1;

    return move;    	
}

void Switch_player(char *player) 
{
    if (*player == P1) {
        *player = P2;
    } else {
        *player = P1;
    }
}

