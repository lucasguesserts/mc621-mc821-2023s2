#include <cstdio>
#include <iostream>
#include <cstdint>
 
#define Vertex int
#define value_t uint64_t

#define maxV 128

// Graph data structure
value_t adj[maxV][maxV];
int numV;

void GRAPHinsertE(Vertex v, Vertex w, value_t prob) {
    adj[v][w] = adj[w][v] = prob;
}

// probabilities and search tree parents of each vertex
double prob[maxV];
Vertex parnt[maxV];

// priority queue data structure
Vertex PQ[maxV];
int PQsz;
 
void PQinit() {
    PQsz = 0;
}
 
int PQempty() {
    return (PQsz == 0);
}
 
void PQinsert(Vertex v) {
    PQ[PQsz++] = v;
}
 
Vertex PQdelmax() {
    Vertex v;
    int i, max_ind;
    double max_prob = 0.0;
    for (i = 0; i < PQsz; i++)
        if (prob[PQ[i]] > max_prob) {
            max_prob = prob[PQ[i]];
            max_ind = i;
        }
    v = PQ[max_ind];
    PQ[max_ind] = PQ[--PQsz];
    return v;
}
 
double max_prob() {
    Vertex v, w;
    double prob_aux;
    for (v = 0; v < numV; v++) {
        prob[v] = 0.0;
        parnt[v] =  -1;
    }
 
    PQinit();
 
    parnt[0] = 0;
    prob[0] = 100.0;
    PQinsert(0);
 
    while (!PQempty()) {
        v = PQdelmax();
        for (w = 0; w < numV; w++)
            if (adj[v][w] > 0) {
                prob_aux = prob[v]*(adj[v][w])/100.0;
                if (parnt[w] == -1) {
                    parnt[w] = v;
                    prob[w] = prob_aux;
                    PQinsert(w);
                }
                else if (prob_aux > prob[w]) {
                    parnt[w] = v;
                    prob[w] = prob_aux;
                }
            }
    }
 
 
    return prob[numV-1];
}
 
void GRAPHinit() {
    int i, j;
    for (i = 0; i < numV; i++)
        for (j = 0; j < numV; j++)
            adj[i][j] = 0;
}
 
int main() {
    int m;
    while ((scanf("%d %d", &numV, &m) != -1) && numV) {
        GRAPHinit();
        while (m--) {
            int i, j;
            unsigned prob;
            std::cin >> i >> j >> prob;
            GRAPHinsertE(i-1, j-1, prob);
        }
        printf("%.6f percent\n", max_prob());
    }
 
    return 0;
}

