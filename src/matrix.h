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


/**/
void
Free_matrix(Matrix**);

/**/
int
Matrix_count_free(const Matrix*);

/**/
int
Fill_matrix(Matrix**, int src);


/**/
int
Get_matrix(const Matrix* pmtx, int row, int col);


/**/
int
Set_matrix(Matrix** ppmtx, int row, int col);


#endif
