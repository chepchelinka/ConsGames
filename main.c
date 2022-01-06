#include <stdio.h>
#include <stdlib.h>

#include "main.h"

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
	
	do 
	{
		// some one won
		if (play_again)
		{
			player = P1;
			counters.games++;
			counters.moves = 0;
		}

		if (counters.moves > 0) {
			Change_matrix(matrix, move.row, move.col, player); // processing errors in future

			if (Win_checker(matrix) == 1) {
				
				matrix = Init_matrix();
				
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

		printf("Games played: %d\n", counters.games);
		printf("P-%c wins: %d\n", P1, counters.p1_wins);
		printf("P-%c wins: %d\n", P2, counters.p2_wins);
		printf("Moves made: %d\n\n", counters.moves);


		printf("Player-%c is moving\n", player);

		move = Get_move();
		counters.moves++;

	} while (Count_free_spaces(matrix) > 0);

	return 0;
}


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
		
		return -1;
	} else if (matrix[row][col] != FREE) {          // cell is already used
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

struct Move Get_move(void)
{
	int row, col;
	int status;

	struct Move move;

	printf("Enter coordinats as: ROW COL (2, 1)\n");

	while ( (status = scanf("%d%d", &row, &col)) != 2 ||
			row < 1 || row > SIZE ||
			col < 1 || col > SIZE)
	{
		if (status != 2) {
			while (getchar() != '\n') ;
		}

		printf("   ### WRONG INPUT ### \ncoordinats must be integers in range (1 -> %d)\n\n", SIZE);
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
	if (matrix[row][col] == matrix[row-1][col-1] &&
		matrix[row][col] == matrix[row-2][col-2]) {
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

			// enougth space in rigth diogonal
			if (row-2 > SIZE && col-2 > SIZE) {
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