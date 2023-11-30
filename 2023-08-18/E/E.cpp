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
# [Squawk Virus](https://open.kattis.com/problems/squawk)

This problem requires us to answer the following: given a graph $G$, a source vertex $s$ and an integer $t>0$,
how many paths of length $t$ with source $s$ exist in $G$?

Solution:
* Let $A$ be the adjacency matrix of $G$;
* Then for each nonnegative integer $i$, and each pair of vertices $x, y$, $A^i_{x,y}$ counts the $x,y$-paths
of length $i$;
* Therefore, the answer to the problem is $\sum_{u} A^t_{s,u}$, i.e., we compute $A^t$ and sum the contents
of line $s$.

Ideally, one should use fast exponentiation for the third step, but it is not actually required by the
online judge, at least in C/C++.

*/

// ==================== Code ====================

#include <cstdint>
#include <iostream>

#define MAXN 100

// typedef unsigned value_t;
typedef uint64_t value_t;
typedef struct {
    value_t mat[MAXN][MAXN];
} Matrix;

Matrix adj;
Matrix pot;
Matrix aux;

using namespace std;

void initialize_matrices(int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj.mat[i][j] = pot.mat[i][j] = 0;
}

void read_matrix(int m) {
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        pot.mat[u][v] = pot.mat[v][u] = adj.mat[u][v] = adj.mat[v][u] = 1;
    }
}

value_t dot(Matrix A, int line, Matrix B, int col, int n) {
    value_t res = 0;
    int k;
    for (k = 0; k < n; k++)
        res += A.mat[line][k] * B.mat[k][col];
    return res;
}

Matrix matrix_mul(Matrix A, Matrix B, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            aux.mat[i][j] = dot(A, i, B, j, n);
    return aux;
}

void matrix_pot(int n, int p) {
    if (p == 1) return;
    matrix_pot(n, p / 2);
    pot = matrix_mul(pot, pot, n);
    if (p % 2) pot = matrix_mul(pot, adj, n);
}

value_t paths_from_source(int s, int n) {
    value_t res = 0;
    int t;
    for (t = 0; t < n; t++)
        res += pot.mat[s][t];
    return res;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    initialize_matrices(n);
    read_matrix(m);
    if (t > 0) {
        matrix_pot(n, t);
        cout << paths_from_source(s, n) << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
