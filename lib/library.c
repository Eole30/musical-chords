#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <gsl/gsl_sf_bessel.h>

/* Elisabeth
 * compiling in linux : gcc -shared -O2 -o library.so -fPIC library.c
 */

struct MLP {
    double*** W;
    double** X;
    double** deltas;
    int32_t L;
    int32_t* d;
};


/*void test_gsl () {
    double x = 5.0;
    double y = gsl_sf_bessel_J0(x);
    printf ("J0(%g) = %.18e\n", x, y);
}*/

void hello() {
    printf("Hello, World!\n");
}

int returns_int(){
    return 1;
}
double returns_double(){
    return 42.42;
}
/*python for reference
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


/* python pour ref
 * # Training
for i in range(0,10000):
  k = np.random.choice(range(0,len(X)))
  g_x_k = predict_linear_model_classification(W, X[k])
  y_k = Y[k]
  diff = y_k - g_x_k
  W[0] = W[0] + 0.01 * diff * 1
  W[1:] = W[1:] + 0.01 * diff * X[k]
 */
double* train_linear_classification(double * weights, double * inputs, double * outputs, int size, int train_iterations){
    int k;
    double g_x_k, y_k, diff;
    for (int i = 0; i < train_iterations ; ++i) {
        srand(time(NULL)); //seed
        k = rand() % size; //get random index between 0 and len(X)
        g_x_k = predict_linear_classification(weights, inputs, size);
        y_k = *(outputs + k);
        diff = y_k - g_x_k;
        *weights += 0.01 * diff;
        for (int j = 1; j < size ; ++j) {
            *(weights + j) += 0.01 * diff * *(inputs + j);
        }
    }
}


double get_random() {
    srand(time(NULL)); //seed
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0; //between -1.0 and 1.0
}

