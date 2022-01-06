#define P1 'X'
#define P2 'O'
#define FREE '~'

#define SIZE 3

// clear console command depends of OS
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
    int p1_wins;
    int p2_wins;
};


/* Init_matrix: create matrix[SIZE][SIZE]
 * and fill matrix by FREE 
 */
int **Init_matrix();

// Print_matrix: printing matrix and other interface
void Print_matrix(int **matrix);

// Count_free_spaces: count all FREE chars in matrix
int Count_free_spaces(int **matrix);

// Get_move: get move from user and returns struct with move coordinats
struct Move Get_move();

/* Change_matrix: replace matrix[row][col] by player const (P1 or P2)
 * end returning code of error
 * 1 - fine
 * -1 - wrong coordinats
 * -2 - cell is already used
 */
int Change_matrix(int **matrix, int row, int col, char player);

// Switch_player: change player by opposite player
void Switch_player(char *player);

/* print_sep_line: prints separator line (+---+---+---+---+)
 * use in Print_matrix()
 */
void print_sep_line();
