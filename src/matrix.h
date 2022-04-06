#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
	const size_t size;
	int** matrix;
} Matrix;



Matrix*
Init_matrix(size_t size);


void
Free_matrix(Matrix*);


int
Matrix_count_free(const Matrix*);


int
Fill_matrix(Matrix*, char src);


#endif
