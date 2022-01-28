// This file contains headers of functions 

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


/* Init_matrix: create matrix[SIZE][SIZE]
 * and fill matrix by FREE 
 */
int **Init_matrix();

// Print_matrix: printing matrix and other interface
void Print_matrix(int **matrix);

// Print_move_info: printing information about the move
void Print_move_info(struct Game_cnts counters, char player);
 
/* Count_free_spaces: count all FREE chars in matrix
 * process some errors with input values
 */
int Count_free_spaces(int **matrix);

// Get_move: get move from user and returns struct with move coordinats
struct Move Get_move(int**matrix);

/* Change_matrix: replace matrix[row][col] by player const (P1 or P2)
 * end returning code of error
 * 1  - fine
 * -1 - wrong coordinats
 * -2 - cell is already used
 * -3 - wrong player const
 */
int Change_matrix(int **matrix, int row, int col, char player);

// Switch_player: change player by opposite player
void Switch_player(char *player);

// Win_checker: checks if win combinations in the matrix
int Win_checker(int **matrix);
