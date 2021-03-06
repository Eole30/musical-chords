#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <gsl/gsl_sf_bessel.h>

/* Elisabeth
 * compiling c in linux : gcc -shared -O2 -o library.so -fPIC library.c
 * c++ compiling : g++ -std=c++14 -c -o library.o library.cpp
 * c++ linking : gcc -shared -o library.so library.o
 */

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
/*
 * without a matrix lib --> gnu gsl if I can get it to work
 */


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


#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
}