#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int argc, char const *argv[])
{
    struct Move move = Get_move();
    printf("Row, Col --> %d, %d\n", move.row, move.col);

    // int ** matrix = Init_matrix();
    // Print_matrix(matrix);
    return 0;
}


int **Init_matrix()
{
    int **matrix = malloc(sizeof(int**) * SIZE);

    for (int i=0; i<SIZE; i++)
    {
        matrix[i] = malloc(sizeof(int *) * SIZE);
        for (int j=0; j<SIZE; j++)
        {
            matrix[i][j] = FREE;
        }
    } 
    
    return matrix;

}

int Change_matrix(int **matrix, int row, int col, char player)
{
    
    if (row >= SIZE || row < 0 ||                   // wrong coordinats
        col >= SIZE || col < 0) {
        
        return -1;
    } else if (matrix[row][col] == FREE) {          // cell is already used
        return -2;
    } else if (player != P1 && player != P2){       // wrong player const
        printf("Change_matrix: wrong player constant: %c\n", player);
        return -3;
    } else {                                        // all fine
        matrix[row][col] = player;
        return 1;
    }
}

void Print_matrix(int **matrix)
{

    print_sep_line();
    
    printf("|   |");
  
    // numbers in row
    for (int i=0; i<SIZE; i++)
    {
        printf(" %d |", i+1);
    }
    putchar('\n');
    print_sep_line();

    for (int i=0; i<SIZE; i++)
    {
        printf("| %d ", i+1);

        for (int j=0; j<SIZE; j++)
        {
            printf("| %c ", matrix[i][j]);
        }

        printf("|\n");
        
        if (i<SIZE-1) 
            print_sep_line();
    }
    print_sep_line();
}

void print_sep_line()
{
    putchar('+');

    for(int i=0; i<=SIZE; i++)
    {
        printf("---+");
    }
    putchar('\n');
}


int Count_free_spaces(int **matrix)
{
    int free_spaces=0;
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            if (matrix[i][j] == FREE)
                free_spaces++;
        }
    }
    return free_spaces;
}

struct Move Get_move()
{
    int row, col;
    int status;
    struct Move move;

    // wrong coordinats for loop
    row = col = -1;

    while ((status = scanf("%d%d", &row, &col)) != 2 ||
     row < 1 || row > SIZE ||
     col < 1 || row > SIZE)
    {
        if (status != 2) {
            while (getchar() != '\n') ;
        }

        printf("Wrong input: coordinats must be integers in range (1 -> %d)\n", SIZE);
        printf("Enter coordinats as: ROW COL (2, 1)\n");
    }

    move.row = row - 1;
    move.col = col - 1;

    return move;    
}

void Switch_player(char *player) 
{

}