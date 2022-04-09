#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "game.h"

#define BUFSIZE 1024
#define COMMANDS_COUNT 3
#define WELCOME_MSG "Welcome to the Tic-Tac.\n" \
					"Version: 2.0\n\n"


// list of all avalible commands
static const char* command_arr[COMMANDS_COUNT] = {
	"exit",
	"help",
	"tictac"	
};


// codes of all avalibal commands 
typedef enum {
	C_UNKNOWN=-1,
	C_EXIT,
	C_HELP,
	C_TICTAC
} command_t;


// contains information about a user's request
typedef struct
{
	int len;
	char input[BUFSIZE];
	command_t cm_code;
} user_req_t;



// return struct with command string and code
static user_req_t
get_user_input(void);


// prints help reference
static void
print_help_ref(void);
 

int main(void)
{
	user_req_t req;
	
    printf(WELCOME_MSG);

	for (;;) {

		// get input from the user
		req = get_user_input();

		// process len exceptions
		if (req.len == -1)
			printf("EOF found. Exiting...\n");
		else if (req.len == 0)
			continue;

		switch (req.cm_code) {

		case C_EXIT:
			printf("Bye...\n");
			exit(EXIT_SUCCESS);
		    break;

		case C_HELP:
			print_help_ref();
			break;

		case C_TICTAC:
			Run_tictac();
			break;

		default:
			printf("Unknown command\n Try \"help\"\n");
			break;
		}

	}
		
    return 0;
}


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


static user_req_t
get_user_input(void)
{
	user_req_t req;

	print_command_invite();

	// get command from user and record len of them
	req.len = Get_command(req.input);

	// unknown command by default 
	req.cm_code = -1;

	// change code of command if command is avalible
	for (int i=0; i<COMMANDS_COUNT; i++) {
		if (!memcmp(command_arr[i], req.input, strlen(command_arr[i]))) {
			req.cm_code = i;
			break;
	    }
	}

	return req;
}


static void
print_help_ref(void)
{
	printf("\nHelp reference:\n");
	printf("\t[command]decoding --> DO\n\n");

	printf("exit   --> drop the programm\n");
	printf("help   --> get help reference\n");
	printf("tictac --> run tic-tac-toe game\n");
	putchar('\n');
} 


static void
print_command_invite(void)
{
	printf("\n    [~]: ");
}
