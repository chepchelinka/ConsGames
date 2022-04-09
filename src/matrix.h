#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
	const size_t size;
	int** matrix;
} Matrix;


/* Init_matrix: return allocated struct with given size and matrix by this size
 * do exit(1) and print error if NULL has been allocated
 */
Matrix*
Init_matrix(size_t size);


/* Free_matrix: free whole struct (rows and cols of matrix and the struct itself)
 */
void
Free_matrix(Matrix**);


/* Get_matrix: return item by coordinats
 * do exit(1) with message about the error
 */
int
Get_matrix(const Matrix* pmtx, int row, int col);


/* Set_matrix: set value to matrix by given coordinats
 * do exit(1) with message about the error
 * return given value
 */
int
Set_matrix(Matrix** ppmtx, int row, int col, int src);


/* Fill_matrix: set all cells by given value
 * Base on Set_matrix(...)
 */
void
Fill_matrix(Matrix**, int src);


#endif
