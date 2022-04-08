#define P1 'X'
#define P2 'O'
#define FREE ' '

#define SIZE 3

#define COMMAND_LEN 1024

// Clear console command depends of OS
#if defined(_WIN32)
    #define CLEAR "cls"

#elif defined(__linux__)
    #define CLEAR "clear"

#endif


struct Move
{
    int row;
    int col;
};

struct Game_cnts
{
    int games;
    int moves;
    int p1_wins;
    int p2_wins;
};


/* print_command_invite: invite user to enter his command
 * define this function in every unit 
 */
static void
print_command_invite(void);


/* Get_command: get command from the user.
 * Doesn't print invite.
 * Cut extra white simbols (' ', '\n', '\t').
 * Ignoring case.
 * Returns len of gotten command.
 */
int Get_command(char *command);


/* Get_move: get coordinats from user
 * use Get_command if user entered not coordinats
 */
struct Move Get_move(int**matrix);


/* Run_tictac: main loop of the game.
 * Defined in src/game/game.c
 */
int Run_tictac();



// Switch_player: change player by opposite player
void Switch_player(char *player);





// NOTE: change next funcs in future

/* Init_matrix: create matrix[SIZE][SIZE]
 * and fill matrix by FREE 
 */
int **Init_matrix();

void Free_matrix();

// Print_matrix: printing matrix and other interface
void Print_matrix(int **matrix);

// Print_move_info: printing information about the move
void Print_move_info(struct Game_cnts counters, char player);
 
/* Count_free_spaces: count all FREE chars in matrix
 * process some errors with input values
 */
int Count_free_spaces(int **matrix);

/* Change_matrix: replace matrix[row][col] by player const (P1 or P2)
 * end returning code of error
 * 1  - fine
 * -1 - wrong coordinats
 * -2 - cell is already used
 * -3 - wrong player const
 */
int Change_matrix(int **matrix, int row, int col, char player);

// Win_checker: checks if win combinations in the matrix
int Win_checker(int **matrix);
