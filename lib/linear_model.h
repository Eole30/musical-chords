//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_LINEAR_MODEL_H
#define LIB_LINEAR_MODEL_H

extern LIB_LINEAR_MODEL_H short predict_linear_classification(double *, double *, int );
extern LIB_LINEAR_MODEL_H double* train_linear_classification(double *, double *, double*, int , int );
extern LIB_LINEAR_MODEL_H double get_random();
extern LIB_LINEAR_MODEL_H double* create_linear_model(int);
#endif //LIB_LINEAR_MODEL_H