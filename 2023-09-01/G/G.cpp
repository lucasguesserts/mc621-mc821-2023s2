// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [106 miles to Chicago](https://www.spoj.com/problems/CHICAGO/)

We want to find a maximum cost path in the graph.
Can be done modifying Dijktra or Floyd-Warshall algorithms.

Needed modifications:

* Instead of compounding edge values by addition, compound by multiplying;
* Instead of minimizing the total value (cost) of the path, maximize the
total value (probability).


*/

// ==================== Code ====================

#include <cstdint>
#include <cstdio>
#include <iostream>

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
        parnt[v] = -1;
    }

    PQinit();

    parnt[0] = 0;
    prob[0] = 100.0;
    PQinsert(0);

    while (!PQempty()) {
        v = PQdelmax();
        for (w = 0; w < numV; w++)
            if (adj[v][w] > 0) {
                prob_aux = prob[v] * (adj[v][w]) / 100.0;
                if (parnt[w] == -1) {
                    parnt[w] = v;
                    prob[w] = prob_aux;
                    PQinsert(w);
                } else if (prob_aux > prob[w]) {
                    parnt[w] = v;
                    prob[w] = prob_aux;
                }
            }
    }

    return prob[numV - 1];
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
            GRAPHinsertE(i - 1, j - 1, prob);
        }
        printf("%.6f percent\n", max_prob());
    }

    return 0;
}
