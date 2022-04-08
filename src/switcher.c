#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
