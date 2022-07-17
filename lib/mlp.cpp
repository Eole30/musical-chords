//
// Created by chepj on 14/07/2022.
//

#include "mlp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Eigen>

MLP* init_MLP(int nlp[], int d_size){
    int *d = npl;
    vector<vector<vector<float>>> W;
    vector<vector<float>> X;
    vector<vector<float>> deltas;

    for(auto l = 0; l < dsize; l++){
        W.push_back(vector<vector<float>>());//push_back est égale a un resize +1 en mieux
        if(l == 0){
            continue;
        }
        for (auto i = 0; i < d[l-1]+1 ; ++i) {
            W[l].push_back(vector<float>());
            for (auto j = 0; j < d[l]+1 ; ++j) {
                W[l][i].push_back(randomPouet(-1.0,1.0));
            }
        }
    }
    for(auto l = 0; l <dsize; l++){
        X.push_back(vector<float>());
        for (auto j = 0; j < d[l]+1 ; ++j) {
            X[l].push_back((j == 0) ? 1.0 : 0.0);
        }
    }

    for (auto l = 0; l <= dsize; l++){
        deltas.push_back(vector<float>());
        for (auto j = 0; j < d[l]+1 ; ++j) {
            deltas[l].push_back(0.0);
        }
    }

    MLP* model = new MLP(d, dsize, W, X, deltas);
    return model;
}

void forward_pass(vector<float>sample_inputs, bool is_classification, MLP* model){

    for ( j = 1; j < model.d[0]+1 ; ++j) {
        model.X[0][j] = sample_inputs[j -1];

        for(l = 0; l <=model.d.size(); l++){
            for ( j = 0; j < model.d[l]+1 ; ++j) {
                float sum_result = 0.0;
                for (i = 0; i < model.d[l-1]+1; i++){
                    sum_result += model.W[l][i][j] * model.X[l-1][i];
                }
                model.X[l][j] = sum_result;
                if (l < model.d.size()-1 || l < is_classification ){
                    model.X[l][j] = tanh(model.X[l][j]);
                }
            }
        }
    }
}

float predict_mlp_model_regression(MLP* model, vector<float>sample_inputs){
    model->forward_pass(sample_inputs, false);
    return model->X[model->dsize-1][1];
}

void destroy_model(MLP* model){

}