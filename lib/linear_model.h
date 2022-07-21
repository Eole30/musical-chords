//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_LINEAR_MODEL_H
#define LIB_LINEAR_MODEL_H

extern "C" float* create_linear_model(int);
extern "C" short predict_linear_classification(float *, int, float *);
extern "C" float predict_linear_model_regression(float *, int, float *);
extern "C" float* train_linear_classification(float *, float *, float*, int , int );
extern "C" float get_random_once();
extern "C" float* train_regression_model(float*, int, float *, int, float *, int);
extern "C" float* train_rosenblatt_linear_model(float *, int, float *, int, float *, int , float);
#endif //LIB_LINEAR_MODEL_H
