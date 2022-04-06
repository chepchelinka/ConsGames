#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"


Matrix*
Init_matrix(size_t size)
{

	Matrix *mtx;
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
	if ((mtx = (Matrix*) malloc(sizeof (Matrix*))) == NULL)  {
		fprintf(stderr, "%s: Init_matrix: can't allocate memory for matrix struct\n", __FILE__);
		exit(EXIT_FAILURE);
	}

	memcpy(mtx, &tmp_mtx, sizeof(tmp_mtx));
	
	return mtx;
	
}


void
Free_matrix(Matrix* matrix);


int
Count_free_matrix(const Matrix*);

