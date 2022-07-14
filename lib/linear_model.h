//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_LINEAR_MODEL_H
#define LIB_LINEAR_MODEL_H

extern LIB_LINEAR_MODEL_H double* create_linear_model(int);
extern LIB_LINEAR_MODEL_H short predict_linear_classification(double *, double *);
extern LIB_LINEAR_MODEL_H double predict_linear_model_regression(double *, double *);
extern LIB_LINEAR_MODEL_H double* train_linear_classification(double *, double *, double*, int , int );
extern LIB_LINEAR_MODEL_H double get_random_once();
extern LIB_LINEAR_MODEL_H double* train_rosenblatt_linear_model(double *, double *, double *, int , float);
#endif //LIB_LINEAR_MODEL_H
