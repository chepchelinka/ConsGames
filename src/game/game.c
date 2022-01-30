#include <stdio.h>

#include "game.h"   // funcs

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
    } while (move.row >= 0 || move.col >= 0);

    return 0;
}


