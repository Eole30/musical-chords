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

double *create_linear_model(int input_dim) {
    double *weights;
    weights = malloc((input_dim + 1) * sizeof(double));
    srand(time(NULL)); //seed
    for (int i = 0; i < (input_dim + 1); i++) {
        weights[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
    return weights;
}


double *train_rosenblatt_linear_model(double *model, double *dataset_inputs, double *dataset_expected_outputs,
                                      int iterations_count = 10, float alpha = 0.01) {
    int input_size = sizeof(model) - 1;
    int sample_count = sizeof(dataset_inputs) / input_size;

    srand(time(NULL));
    for (int i = 0; i < iterations_count; i++) {
        int k = rand() % sample_count;
        double Xk[input_size];
        int temp = 0;
        for (int j = k * input_size; j < (k + 1) * input_size; ++j) {
            Xk[temp] = dataset_inputs[j];
            temp++;
        }
        double Yk = dataset_expected_outputs[k * 1];
    }
}


double predict_linear_model_regression(double *model, double *imputs) {
    double sum_rslt = model[0];
    for (int i = 1; i < sizeof(model); ++i) {
        sum_rslt += model[i] * imputs[i - 1];
    }
    return sum_rslt;
}

short predict_linear_classification(double *model, double *imputs) {
    double pred = predict_linear_model_regression(model, imputs);
    //double rslt;
    //if(pred >= 0){return 1.0;}else{return -1.0;}
    return (pred >= 0) ? 1.0 : -1.0;
}

//double *train_linear_classification(double *weights, double *inputs, double *outputs, int size, int train_iterations) {
//    int k;
//    double g_x_k, y_k, diff;
//    for (int i = 0; i < train_iterations; ++i) {
//        srand(time(NULL)); //seed
//        k = rand() % size; //get random index between 0 and len(X)
//        g_x_k = predict_linear_classification(weights, inputs, size);
//        y_k = *(outputs + k);
//        diff = y_k - g_x_k;
//        *weights += 0.01 * diff;
//        for (int j = 1; j < size; ++j) {
//            *(weights + j) += 0.01 * diff * *(inputs + j);
//        }
//    }
//    return weights;
//}

