#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"


Matrix*
Init_matrix(size_t size)
{

	Matrix *pmtx;
	Matrix tmp_mtx={size};


	// allocate memory for matrix rows
	if ((tmp_mtx.matrix = (int**) malloc(size * sizeof(int**))) == NULL) {		
		fprintf(stderr, "%s: Init_matrix: can't allocate memory for matrix row\n", __FILE__);
		exit(EXIT_FAILURE);
	}

	// allocate memory for matrix cols
	for (int i=0; i<size; i++) {
		if ((tmp_mtx.matrix[i] = (int*) malloc(size * sizeof (int*))) == NULL) {
			fprintf(stderr, "%s: Init_matrix: can't allocate memory for matrix col\n", __FILE__);
			exit(EXIT_FAILURE);
		}
	}

	// can't allocate memory for returning struct
	if ((pmtx = (Matrix*) malloc(sizeof (Matrix*))) == NULL)  {
		fprintf(stderr, "%s: Init_matrix: can't allocate memory for matrix struct\n", __FILE__);
		exit(EXIT_FAILURE);
	}

	memcpy(pmtx, &tmp_mtx, sizeof(tmp_mtx));
	
	return pmtx;
	
}


void
Free_matrix(Matrix** ppmtx)
{
	size_t size =(*ppmtx)->size;

	// free cols of matrix
	for (int i=0; i<size; i++) {
		free( (*ppmtx)->matrix[i] );
	}

	// free rows of matrix
	free((*ppmtx)->matrix);

	// free the struct
	free((*ppmtx));
}


int
Get_matrix(const Matrix* pmtx, int row, int col)
{
	size_t size = pmtx->size;

 	// check if coordinates in available range
    if (row >= size || row < 0 ||
        col >= size || col < 0) {

		fpritnf(stderr, "%s: Get_matrix: coordiants (%d:%d) not in avalibal range (%d)\n", __FILE__, row, col, size);
		exit(EXIT_FAILURE);
	}

	// return item of matrix by give coorginats
	return pmtx->matrix[row][col];	
}


int
Set_matrix(Matrix** ppmtx, int row, int col, int src)
{
	size_t size = (*ppmtx)->size;

	// check if coordinates in available range
    if (row >= size || row < 0 ||
        col >= size || col < 0) {

		fpritnf(stderr, "%s: Set_matrix: coordiants (%d:%d) not in avalibal range (%d)\n", __FILE__, row, col, size);
		exit(EXIT_FAILURE);
	}

	// set and return given value
	return ((*ppmtx)->matrix[row][col] = src);

}


int
Fill_matrix(Matrix** ppmtx, int src);

