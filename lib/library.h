#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H


typedef struct {
    double*** W;
    double** X;
    double** deltas;
    int L;
    int* d;
} MLP;

void hello();
int returns_int();
double returns_double();
MLP* init_MLP(int, int*);
void destroy_model(MLP*);
short predict_linear_classification(double *, double *, int );
double* train_linear_classification(double *, double *, double*, int , int );
double get_random();
void test_gsl ();
#endif //LIB_LIBRARY_H
