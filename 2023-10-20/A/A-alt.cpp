#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAX     1000

int table[MAX+1][MAX+1];

unsigned lcs(string A, string B) {
    int n = A.size(), m = B.size();
    int i, j;

    memset(table, 0, sizeof table);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1])
                table[i][j] = table[i-1][j-1] + 1;
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }

  return table[n][m];
}

int main() {
    string A, B;
    while (getline(cin, A)) {
        getline(cin, B);
        cout << lcs(A, B) << endl;
    }
    return 0;
}
