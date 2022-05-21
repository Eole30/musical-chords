#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Elisabeth
 * compiling in linux : gcc -shared -O2 -o library.so -fPIC library.c
 */

void hello() {
    printf("Hello, World!\n");
}

int returns_int(){
    return 1;
}

/*python
 * def predict_linear_model_classification(model_weights: np.ndarray, inputs: np.ndarray):
    total_sum = 1 * model_weights[0] + np.sum(model_weights[1:] * inputs)
    return 1 if total_sum >= 0 else -1
 */

/*
 * without a matrix lib --> gnu gsl or eigen
 */
short predict_linear_classification(double * weights, double * inputs, int size){
    double total_sum;
    total_sum = *weights;
    for (int i = 0; i < size; ++i) {
        total_sum += *(weights + i + 1) * *(inputs + i);
    }
    return (total_sum >= 0) ? 1 : -1;
}

double get_random() {
    srand(time(NULL)); //seed
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0; //between -1.0 and 1.0
}

