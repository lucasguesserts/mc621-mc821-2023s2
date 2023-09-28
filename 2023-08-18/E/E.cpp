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
