#include <stdio.h>

#include "main.h"   // funcs
#include "common.h" // constants

int main(int argc, char const *argv[])
{
    int **matrix = Init_matrix();
    
    struct Game_cnts counters;
    struct Move move;

    // moving player
    char player=P1;

    int play_again=0;

    // null all counters
    counters.games = counters.p1_wins = counters.p2_wins = counters.moves = 0;
    
    // infiniti loop
    do 
    {
        // someone won
        if (play_again)
        {
            // reset matrix
            matrix = Init_matrix();

            // set first moving player
            player = P1;

            // increase game counter
            counters.games++;

            // reset move counter
            counters.moves = 0;

            // reset state
            play_again=0;
        }
        
        // if not first move (do loop peculiarities)
        if (counters.moves > 0) {
            Change_matrix(matrix, move.row, move.col, player);

            if (Win_checker(matrix) == 1) {
                
                if (player == P1)
                    counters.p1_wins++;
                else
                    counters.p2_wins++;
                
                play_again=1;
                
                continue;
                
            } else {
                Switch_player(&player);     
            }
        }

        Print_matrix(matrix);

        // if all free cells in matrix are out
        if (Count_free_spaces(matrix) == 0) {
            play_again = 1;
            continue;
        }

        printf("Games played: %d\n", counters.games);
        printf("P-%c wins: %d\n", P1, counters.p1_wins);
        printf("P-%c wins: %d\n", P2, counters.p2_wins);
        printf("Moves made: %d\n\n", counters.moves);


        printf("Player-%c is moving\n", player);

        move = Get_move(matrix);
        counters.moves++;
    } while (1);

    return 0;
}

struct Move Get_move(int **matrix)
{
    int row, col;
    int status;

    struct Move move;

    printf("Enter coordinats as: ROW COL (2, 1)\n");

    while ( (status = scanf("%d%d", &row, &col)) != 2 ||
            row < 1 || row > SIZE  ||
            col < 1 || col > SIZE  ||

            matrix[row-1][col-1] != FREE
            ) 
    {

        if (status != 2) {							// string was entered
            while (getchar() != '\n') ;
            printf("   ### WRONG INPUT ### \nCoordinats must be integers in range (1 -> %d)\n\n", SIZE);
        } else if (row < 1 || row > SIZE || col < 1 || col > SIZE)  { // indices out 
            printf("   ### WRONG INPUT ### \nCoordinats must be integers in range (1 -> %d)\n\n", SIZE);
        } else if (matrix[row-1][col-1] != FREE) {	// cell is already used
            printf("   ### CELL IS USED ###\nThis cell is already used. Try to get anouther one: \n");
        }
        printf("Enter coordinats as: ROW COL (2, 1)\n");
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

// Win_checker funcs
int horizontal_check(int **matrix, int row, int col)
{
    int *my_row = matrix[row];

    // if there are 3 the same values in line
    if (my_row[col] == my_row[col+1] &&
        my_row[col] == my_row[col+2]) {
        return 1;
    } else {
        return 0;
    }
}

int vertical_check(int **matrix, int row, int col)
{
    // if there are 3 the same values i column
    if (matrix[row][col] == matrix[row+1][col] &&
        matrix[row][col] == matrix[row+2][col]) {
        return 1;	
    } else {
        return 0;
    }
}

int r_diagonally_check(int **matrix, int row, int col)
{
    // if there are 3 the same values in right diagonal
    if (matrix[row][col] == matrix[row+1][col+1] &&
        matrix[row][col] == matrix[row+2][col+2]) {
        return 1;
    } else {
        return 0;
    }
}

int l_diagonally_check(int **matrix, int row, int col)
{
    // if there are 3 the same values in left diagonal
    if (matrix[row][col] == matrix[row+1][col-1] &&
        matrix[row][col] == matrix[row+2][col-2]) {
        return 1;
    } else {
        return 0;
    }
}

int Win_checker(int **matrix)
{
    int horiz, vert, rdiog, ldiog;


    for (int row=0; row<SIZE; row++)
    {
        for (int col=0; col<SIZE; col++)
        {
            // pass if FREE
            if (matrix[row][col] == FREE) 
                continue;

            horiz = vert = rdiog = ldiog = 0;

            // enougth space in row
            if (col+2 < SIZE) {
                horiz = horizontal_check(matrix, row, col);
            }

            // enougth space in column
            if (row+2 < SIZE) {
                vert = vertical_check(matrix, row, col);
            }

            // enougth space in rigth diogonal
            if (row+2 < SIZE && col+2 < SIZE) {
                rdiog = r_diagonally_check(matrix, row, col);
            }

            // enougth space in left diogonal
            if (row+2 <	SIZE && col-2 >= 0) {
                ldiog = l_diagonally_check(matrix, row, col);
            }

            if (vert || horiz || rdiog || ldiog)
            {
                return 1;
            }
        }
    }
    return 0;
}
