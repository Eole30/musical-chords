//
// Created by chepj on 14/07/2022.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Eigen/Eigen>
#include <vector>
#include <random>
#include "mlp.h"

using namespace std;
using namespace Eigen;


class MLP{
public:
    int* d;
    int d_size;
    vector<vector<vector<float>>> W;
    vector<vector<float>> X;
    vector<vector<float>> deltas;
public:
    MLP(int* a,int a_size, vector<vector<vector<float>>> B,vector<vector<float>> C,vector<vector<float>> alphas){
        d = a;
        d_size=a_size;
        W = B;
        X = C;
        deltas = alphas;
    }

    void forward_pass(vector<float> sample_inputs, bool is_classification) {

        for (auto j = 1; j < d[0] + 1; ++j) {
            X[0][j] = sample_inputs[j - 1];

            for (auto l = 0; l <= d_size; l++) {
                for (auto j = 0; j < d[l] + 1; ++j) {
                    float sum_result = 0.0;
                    for (auto i = 0; i < d[l - 1] + 1; i++) {
                        sum_result += W[l][i][j] * X[l - 1][i];
                    }
                    X[l][j] = sum_result;
                    if (l < d_size - 1 || l < is_classification) {
                        X[l][j] = tanh(X[l][j]);
                    }
                }
            }
        }
    }
    /*
    void train_stochastic_gradient_backpropagation(vector<float>flattened_dataset_inputs, vector<float>flattened_expected_outputs, bool is_classification,float alpha = 0.01,int iterations_count = 1000){
        vector<vector<vector<float>>> W;
        vector<vector<float>> X;
        vector<vector<float>> deltas;

        int L = d.size()-1;
        int input_dim = d[0];
        int output_dim = d[L];
        int samples_count = flattened_dataset_inputs.size() / input_dim;

        for(it = 0; it < iterations_count;it ++){
            k = (int) (randomDistribution(0, samples_count - 1));
            vector<float> sample_inputs = reinterpret_cast<vector<float, allocator<float>> &&>(flattened_dataset_inputs[k *input_dim, (k + 1) * input_dim]);
            vector<float> sample_expected_outputs = reinterpret_cast<vector<float, allocator<float>> &&>(flattened_expected_outputs[
                    k * output_dim, (k + 1) * output_dim]);

            forward_pass(sample_inputs, is_classification);

            for (j = 1; d[L]+1 ; j++){
                deltas[L][j] = X[L][j] - sample_expected_outputs[j-1];
                if(is_classification){
                    deltas[L][j] = (1 - X[L][j]* X[L][j]) * deltas[L][j];
                }
            }
            for (l = L+1; l>1; l--){
                for (i = 0; i < d[l - 1]+1; i++){
                    sum_result = 0.0;
                    for (j = 1; j< d[l]+1; j++){
                        sum_result += W[l][i][j]* deltas[l][j];
                    }
                    deltas[l-1][i] = (1 - X[l-1][i]* X[l-1][i]) * sum_result;
                }
            }
            for (l = 1; l < L+1; l++){
                for (i = 0; d[l-1]+1; i++){
                    for (j = 1; d[l]+1; j++){
                        W[l][i][j] += -alpha * X[l-1][i]* deltas[l][j];
                    }
                }
            }
        }
    }
     */
};

class MLP init_MLP(int mlp[], int d_size) {
    int *d = mlp;
    vector<float> W1;
    vector<vector<vector<float>>> W;
    vector<vector<float>> X;
    vector<vector<float>> deltas;

    for (auto l = 1; l < d_size; l++) {
        W.push_back(vector < vector < float >> ());//push_back est égale a un resize +1 en mieux
        for (auto i = 0; i < d[l - 1] + 1; ++i) {
            W[l].push_back(vector<float>());
            for (auto j = 0; j < d[l] + 1; ++j) {
                W[l][i].push_back(randomDistribution(-1.0, 1.0));
            }
        }
    }
    for (auto l = 0; l < d_size; l++) {
        X.push_back(vector<float>());
        for (auto j = 0; j < d[l] + 1; ++j) {
            X[l].push_back((j == 0) ? 1.0 : 0.0);
        }
    }

    for (auto l = 0; l <= d_size; l++) {
        deltas.push_back(vector<float>());
        for (auto j = 0; j < d[l] + 1; ++j) {
            deltas[l].push_back(0.0);
        }
    }

    MLP model(d, d_size, W, X, deltas); //d, d_size, W, X, deltas
//    model.d = d;
//    model.d_size = d_size;
//    model.W = W;
//    model.X = X;
//    model.deltas = deltas;
    return model;
}

float randomDistribution(float start, float end) {
    random_device rd;
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(start, end);
    return dis(gen);
}
/*
void train_regression_stochastic_backprop_mlp_model (MLP* model, vector<float>flattened_dataset_inputs, vector<float>flattened_expected_outputs, float alpha = 0.01, int iterations_count = 1000){
    model->train_stochastic_gradient_backpropagation(flattened_dataset_inputs, flattened_expected_outputs, false, alpha, iterations_count);
}
*/
float predict_mlp_model_classification(MLP mlp, vector<float>sample_inputs){
    mlp.forward_pass(sample_inputs, true);
    return mlp.X[mlp.d_size - 1][1];
}

float predict_mlp_model_regression(MLP mlp, vector<float>sample_inputs){
    mlp.forward_pass(sample_inputs, false);
    return mlp.X[mlp.d_size - 1][1];
}

void destroy_model(MLP mlp) {

}