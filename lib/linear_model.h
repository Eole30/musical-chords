//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_LINEAR_MODEL_H
#define LIB_LINEAR_MODEL_H

extern "C" double* create_linear_model(int);
extern "C" short predict_linear_classification(double *, int, double *);
extern "C" double predict_linear_model_regression(double *, int, double *);
extern "C" double* train_linear_classification(double *, double *, double*, int , int );
extern "C" double get_random_once();
extern "C" double* train_regression_model(double*,double *, double *);
extern "C" double* train_rosenblatt_linear_model(double *, int, double *, int, double *, int , float);
#endif //LIB_LINEAR_MODEL_H
