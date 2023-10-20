#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAX     100

#define INDEL       (-1)
#define MATCH       (+0)
#define MISMATCH    (-1)

int table[MAX+1][MAX+1];

int score(string A, string B) {
    int n = A.length(), m = B.length();
    int i, j;

    memset(table, 0, sizeof table);
    for (i = 1; i <= n; i++)
        table[i][0] = i * INDEL;
    for (j = 1; j <= m; j++)
        table[0][j] = j * INDEL;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? MATCH : MISMATCH); // cost for match or mismatches
            table[i][j] = max(table[i][j], table[i - 1][j] + INDEL); // delete
            table[i][j] = max(table[i][j], table[i][j - 1] + INDEL); // insert
        }
    }

  return table[n][m];
}

int main() {
    int ncases;
    scanf("%d\n", &ncases);
    while (ncases--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);
        cout << -score(A, B) << endl;
    }
    return 0;
}
