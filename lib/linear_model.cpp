//
// Created by chepj on 14/07/2022.
//

#include "linear_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Eigen>

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
double* train_regression_model(double *model, int model_size, double *dataset_inputs, int dataset_size, double *dataset_expected_outputs, int expected_size){
    int input_size = model_size - 1;
    int output_size = expected_size;

    Eigen::MatrixXf X(input_size, 1);
    Eigen::Vector3f vectorX(dataset_inputs);
    X << vectorX;

    Eigen::MatrixXf Y(output_size, 1);
    Eigen::Vector3f vectorY(dataset_expected_outputs);
    Y << vectorY;

    Eigen::MatrixXf W = (((X.transpose() * X).inverse()) * X.transpose()) * Y;
    model = W.data();
    return model;
}

extern "C"
double *train_rosenblatt_linear_model(double *model, int model_size, double *dataset_inputs, int dataset_size, double *dataset_expected_outputs,
                                      int iterations_count, float alpha) {
    int input_size = model_size - 1;
    int sample_count = dataset_size / input_size;
    double *Xk;
    double yk, gXk;
    int temp;

    srand(time(NULL));
    for (int i = 0; i < iterations_count; i++) {
        int k = rand() % sample_count;
        Xk = new double [input_size];
        temp = 0;
        for (int j = k * input_size; j < (k + 1) * input_size; ++j) {
            Xk[temp] = dataset_inputs[j];
            temp++;
        }
        yk = dataset_expected_outputs[k];
        gXk = predict_linear_classification(model, model_size, Xk);
        model[0] += alpha * (yk - gXk) * 1.0;
        for (int j = 1; j < model_size; ++j) {
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


