#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
using namespace std;

#define MAX     5000

#define INDEL       (+0)
#define MATCH       (+1)
#define MISMATCH    (-(1 << 30))

int64_t table[MAX+1][MAX+1];

unsigned lcs_palindrome(string A, int n) {
    int i, j;
    string B(A);
    reverse(B.begin(), B.end());

    //cout << "comparing " << A << " and " << B << endl;

    memset(table, 0, sizeof table);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            table[i][j] = table[i-1][j-1] + (A[i-1] == B[j-1] ? MATCH : MISMATCH); // cost for match or mismatches
            table[i][j] = max(table[i][j], table[i-1][j]);
            table[i][j] = max(table[i][j], table[i][j-1]);
        }
    }

    return table[n][n];
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << n-lcs_palindrome(s, n) << endl;
    return 0;
}
