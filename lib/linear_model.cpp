//
// Created by chepj on 14/07/2022.
//

#include "linear_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Eigen/Dense.h>

/* Elisabeth
 * g++ -fPIC linear_model.cpp -shared -o library.so
 */

extern "C"
double get_random_once() {
    srand(time(NULL)); //seed, call only once
    return ((double) rand() / RAND_MAX) * 2.0 - 1.0; //between -1.0 and 1.0
}

extern "C"
double *create_linear_model(int input_dim) {
    double *weights;
    weights = new double[input_dim + 1];
    srand(time(NULL)); //seed
    for (int i = 0; i < (input_dim + 1); i++) {
        weights[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    return weights;
}
extern "C"
double* train_regression_model(double *model, double *dataset_inputs, double *dataset_expected_outputs){
    int input_size = sizeof(model) - 1;
    int sample_count = sizeof(dataset_inputs) / input_size;

    //x = dataset_inputs;
    double* y = dataset_expected_outputs;
    return model;
}
extern "C"
double *train_rosenblatt_linear_model(double *model, int model_size, double *dataset_inputs, int dataset_size, double *dataset_expected_outputs,
                                      int iterations_count, float alpha) {
    int input_size = model_size - 1;
    int sample_count = dataset_size / input_size;

    srand(time(NULL));
    for (int i = 0; i < iterations_count; i++) {
        int k = rand() % sample_count;
        double Xk[input_size];
        int temp = 0;
        for (int j = k * input_size; j < (k + 1) * input_size; ++j) {
            Xk[temp] = dataset_inputs[j];
            temp++;
        }
        double yk = dataset_expected_outputs[k * 1];
        double gXk = predict_linear_classification(model, model_size, Xk);
        model[0] += alpha * (yk - gXk) * 1.0;
        for (int j = 1; j < sizeof(model); ++j) {
            model[j] += alpha * (yk - gXk) * Xk[j -1];
        }
    }

    return model;
}

extern "C"
double predict_linear_model_regression(double *model, int model_size, double *inputs) {
    double sum_rslt = model[0];
    for (int i = 1; i < model_size; ++i) {
        sum_rslt += model[i] * inputs[i - 1];
    }
    return sum_rslt;
}
extern "C"
short predict_linear_classification(double *model, int model_size, double *inputs) {
    double pred = predict_linear_model_regression(model, model_size, inputs);
    //double rslt;
    //if(pred >= 0){return 1.0;}else{return -1.0;}
    return (pred >= 0) ? 1.0 : -1.0;
}


