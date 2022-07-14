//
// Created by chepj on 14/07/2022.
//

#include "linear_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double get_random_once() {
    srand(time(NULL)); //seed
    return ((double) rand() / RAND_MAX) * 2.0 - 1.0; //between -1.0 and 1.0
}

double* create_linear_model(int input_dim) {
    double *weights;
    weights = malloc((input_dim + 1) * sizeof(double));
    srand(time(NULL)); //seed
    for (int i = 0; i < (input_dim + 1); i++) {
        weights[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    return weights;
}

short predict_linear_model_regression(double * model, double * imputs){
    double sum_rslt = model[0];
    for (int i = 1; i < sizeof(model); ++i) {
        sum_rslt += model[i] * imputs[i-1];
    }
    return sum_rslt;
}

short predict_linear_classification(double *weights, double *inputs, int size) {
    double total_sum;
    total_sum = *weights;
    for (int i = 0; i < size; ++i) {
        total_sum += *(weights + i + 1) * *(inputs + i); //probablement un dépassement de taille
    }
    return (total_sum >= 0) ? 1 : -1;
}

double *train_linear_classification(double *weights, double *inputs, double *outputs, int size, int train_iterations) {
    int k;
    double g_x_k, y_k, diff;
    for (int i = 0; i < train_iterations; ++i) {
        srand(time(NULL)); //seed
        k = rand() % size; //get random index between 0 and len(X)
        g_x_k = predict_linear_classification(weights, inputs, size);
        y_k = *(outputs + k);
        diff = y_k - g_x_k;
        *weights += 0.01 * diff;
        for (int j = 1; j < size; ++j) {
            *(weights + j) += 0.01 * diff * *(inputs + j);
        }
    }
    return weights;
}

