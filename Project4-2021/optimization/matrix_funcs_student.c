#include "matrix.h"

void get_every_fifth_student(const matrix_t *matrix, long results[RESULTS_LEN]) {
    long r0 = 0;
    long r1 = 0;
    long r2 = 0;
    long r3 = 0;
    long r4 = 0;            //Creates five long variables to hold the sums for all 4 buckets
    register int i = 0;
    register int j = 0;     //ints used as counters are stored in register instead of memory for faster access
    for (i = 0; i < matrix->nrows; i++) {
        int y = ((i)*((matrix)->ncols));    //takes part of the MGET function and calculates it before second loop so that the same number is not repeatedly calculated
        int *ptr = &matrix->data[y];        //sets a pointer to the location of the matrix array at the location of the desired row
        for (j = 0; j < matrix->ncols-5; j += 5) {
            r0 += *(ptr + j);               
            r1 += *(ptr + j + 1);
            r2 += *(ptr + j + 2);
            r3 += *(ptr + j + 3);
            r4 += *(ptr + j + 4);       //adds j to pointer for desired column, then adds 0-4 to every number in the row to the correct bucket
        }                               //there are 5 variables which are each added to, this increases efficiency
        for (; j< matrix->ncols; j++) {
            int q = j % RESULTS_LEN;
            results[q] += MGET(matrix, i, j);
        }       //cleanup function which gets any numbers not included in the optimized for loop, this isn't optimized because there are only 9 max number not accounted for
    }
    results[0] += r0;
    results[1] += r1;
    results[2] += r2;
    results[3] += r3;
    results[4] += r4; 
}   //all numbers are added to their buckets in the return array from their temp integer variables

long get_every_student(const matrix_t *matrix) {
    long sum = 0;
    int size = matrix->nrows * matrix->ncols;   //gets size of the array
    int *ptr = &matrix->data[0];                //sets pointer to the first element in the matrix array
    int i = 0;      
    for (; i < size-5; i+=5) {
        sum += *(ptr + i) + *(ptr + i + 1) + *(ptr + i + 2) + *(ptr + i + 3) + *(ptr + i + 4);
    }   //has 5 accumulators adding to the return variable from the pointer, plus the number of accumulators plus 0 through 4 to get all numbers
    for (; i < size; i++) {
        sum += *(ptr + i);
    }   //cleanup loop to get numbers at the end which may have been cut off by first loop
    return sum;
}