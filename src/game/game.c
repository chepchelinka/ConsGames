#include <stdio.h>

#include "game.h"   // funcs
#include "common.h" // constants

int Game_loop()
{
    int **matrix = Init_matrix();
    
    struct Game_cnts counters;
    struct Move move;

    // moving player
    char player=P1;

    int play_again=0;

    // null all counters
    counters.games = counters.p1_wins = counters.p2_wins = counters.moves = 0;
    
    printf("@@@@\n");
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

        Print_move_info(counters, player);

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

