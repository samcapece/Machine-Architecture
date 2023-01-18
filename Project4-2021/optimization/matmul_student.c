#include "matrix.h"

void matmul_student(const matrix_t *A, const matrix_t *B, matrix_t *C) {
    for (int i = 0; i < A->nrows; i++) {
        int y = ((i)*((A)->ncols));             //gets location of desired row for A, saves time of repeatedly doing this calculation in loop
        int *pa = &A->data[y];                  //creates a pointer for A at the location of the desired row
        for (int j = 0; j < A->ncols; j++) {    //2nd and 3rd loops are switched so that A's rows and columns are accessed before B's columns, this considerably sped up the code
            int k = 0;
            int x = ((j)*((B)->ncols));         //gets location of desired row for B, saves time of repeatedly doing this calculation in loop
            int *pb = &B->data[x];              //creates a pointer for B at the location of the desired row
            for (k = 0; k < B->ncols; k++) {
                MGET(C, i, k) += *(pa + j) * *(pb + k);     //gets the location of the desired position in the solution matrix then adds the multiple of a and b
            }                                               //a has a pointer to its row location then j is added to it to get to the correct column
        }                                                   //b also has a pointer to its row, k is added for correct column, b's rows are the same as a's columns
    }
}
