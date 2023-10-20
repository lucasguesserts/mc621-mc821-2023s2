#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
using namespace std;

#define MAX     1000

#define INDEL       (+0)
#define MATCH       (+1)
#define MISMATCH    (-(1 << 30))

int64_t table[MAX+1][MAX+1];

unsigned lcs(string A, string B) {
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
    string A, B;
    while (getline(cin, A)) {
        getline(cin, B);
        cout << lcs(A, B) << endl;
    }
    return 0;
}
