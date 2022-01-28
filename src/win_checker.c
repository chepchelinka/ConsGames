#include "common.h" 

/* horizontal_check:  checks if horizontal combination is win
 * using in Win_checker()
 *			! start
 *			X X X 
 *			# # #
 *			# # #
 */
static int horizontal_check(int **matrix, int row, int col)
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

/* vertical_check:    checks if vertical combination is win
 * using in Win_checker()
 *			! start
 *			X # #
 *  	        	X # #
 * 			X # #
 */
static int vertical_check(int **matrix, int row, int col)
{
    // if there are 3 the same values i column
    if (matrix[row][col] == matrix[row+1][col] &&
        matrix[row][col] == matrix[row+2][col]) {
        return 1;	
    } else {
        return 0;
    }
}

/* r_diagonally_check:checks if right diagonally combination is win
 * using in Win_checker()
 *			! start
 *                      X # #
 * 			# X #
 * 			# # X
 */
static int r_diagonally_check(int **matrix, int row, int col)
{
    // if there are 3 the same values in right diagonal
    if (matrix[row][col] == matrix[row+1][col+1] &&
        matrix[row][col] == matrix[row+2][col+2]) {
        return 1;
    } else {
        return 0;
    }
}

/* l_diagonally_check:checks if left diagonally combination is win
 * using in Win_checker()
 *                          ! start
 * 			# # X
 * 			# X #
 * 			X # #
 */
static int l_diagonally_check(int **matrix, int row, int col)
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

