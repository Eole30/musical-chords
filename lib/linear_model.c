//
// Created by chepj on 14/07/2022.
//

#include "linear_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



short predict_linear_classification(double * weights, double * inputs, int size){
    double total_sum;
    total_sum = *weights;
    for (int i = 0; i < size; ++i) {
        total_sum += *(weights + i + 1) * *(inputs + i); //probablement un dépassement de taille
    }
    return (total_sum >= 0) ? 1 : -1;
}

double* train_linear_classification(double * weights, double * inputs, double * outputs, int size, int train_iterations){
    int k;
    double g_x_k, y_k, diff;
    for (int i = 0; i < train_iterations ; ++i) {
        srand(time(NULL)); //seed
        k = rand() % size; //get random index between 0 and len(X)
        g_x_k = predict_linear_classification(weights, inputs, size);
        y_k = *(outputs + k);
        diff = y_k - g_x_k;
        *weights += 0.01 * diff;
        for (int j = 1; j < size ; ++j) {
            *(weights + j) += 0.01 * diff * *(inputs + j);
        }
    }
    return weights;
}

double get_random() {
    srand(time(NULL)); //seed
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0; //between -1.0 and 1.0
}

