//
// Created by chepj on 14/07/2022.
//

#ifndef LIB_MLP_H
#define LIB_MLP_H

typedef struct {
    double*** W;
    double** X;
    double** deltas;
    int L;
    int* d;
} MLP;

MLP* init_MLP(int, int*);
void destroy_model(MLP*);
#endif //LIB_MLP_H
