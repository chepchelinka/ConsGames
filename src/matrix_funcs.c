#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int **Init_matrix(void)
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
        
        printf("Change_matrix: wrong coordinats\n");
        return -1;
    } else if (matrix[row][col] != FREE) {          // cell is already used
        printf("Change_matrix: this cell is alredy used\n");
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
    // clear console 
    system(CLEAR);

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
    putchar('\n');
}

void print_sep_line(void)
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


