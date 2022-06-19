#pragma once

#ifdef LIB_LIBRARY_EXPORT
#define LIB_LIBRARY_H __declspec(dllexport)
#else
#define LIB_LIBRARY_H __declspec(dllimport)
#endif


typedef struct {
    double*** W;
    double** X;
    double** deltas;
    int L;
    int* d;
} MLP;

extern LIB_LIBRARY_H void hello();
extern LIB_LIBRARY_H int returns_int();
extern LIB_LIBRARY_H double returns_double();
extern LIB_LIBRARY_H MLP* init_MLP(int, int*);
extern LIB_LIBRARY_H void destroy_model(MLP*);
extern LIB_LIBRARY_H short predict_linear_classification(double *, double *, int );
extern LIB_LIBRARY_H double* train_linear_classification(double *, double *, double*, int , int );
extern LIB_LIBRARY_H double get_random();
extern LIB_LIBRARY_H void test_gsl ();

