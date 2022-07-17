//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_MLP_H
#define LIB_MLP_H

typedef struct MLP {
    int* d;
    int d_size;
    vector<vector<vector<float>>> W;
    vector<vector<float>> X;
    vector<vector<float>> deltas;
};

MLP* init_MLP(int, int*);
void forward_pass(vector<float>, bool, MLP*);
void train_stochastic_gradient_backpropagation(vector<float>, vector<float>, bool, float, int);
void train_classification_stochastic_backprop_mlp_model (MLP*, vector<float>, vector<float>, float, int);
void train_regression_stochastic_backprop_mlp_model (MLP*, vector<float>, vector<float>, float , int);
float predict_mlp_model_classification(MLP*, vector<float>);
float predict_mlp_model_regression(MLP*, vector<float>)
void destroy_model(MLP*);
#endif //LIB_MLP_H
