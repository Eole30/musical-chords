//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_MLP_H
#define LIB_MLP_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Eigen/Eigen>
#include <vector>
float randomDistribution(float, float);
MLP* init_MLP(int, int*);
void forward_pass(std::vector<float>, bool, MLP*);
void train_stochastic_gradient_backpropagation(std::vector<float>, std::vector<float>, bool, float, int);
void train_classification_stochastic_backprop_mlp_model (MLP*, std::vector<float>, std::vector<float>, float, int);
void train_regression_stochastic_backprop_mlp_model (MLP*, std::vector<float>, std::vector<float>, float , int);
float predict_mlp_model_classification(MLP*, std::vector<float>);
float predict_mlp_model_regression(MLP*, std::vector<float>);
void destroy_model(MLP*);
#endif //LIB_MLP_H
