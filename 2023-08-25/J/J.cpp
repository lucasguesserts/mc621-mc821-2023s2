#include <iostream>
#include <cstdint>

/* https://codeforces.com/problemset/problem/1433/E
 *
 * accepted!
 *
**/

#define MAXN    20

using namespace std;

int main () {
    uint64_t fact[MAXN];
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAXN; i++) fact[i] = fact[i-1]*i;

    int n;
    cin >> n;
    cout << ((2*fact[n-1])/n) << endl;
}
