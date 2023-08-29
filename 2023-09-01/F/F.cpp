#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cmath>

#define MAXN    25

using namespace std;
using value_t = uint64_t;

value_t combination[2*MAXN][2*MAXN+1] = {};

void init_comb() {
    for (int i = 0; i < 2*MAXN; i++) {
        combination[i][0] = combination[i][i] = 1;
    }
}

// returns n choose k
value_t comb(int n, int k) {
    if (!combination[n][k])
        combination[n][k] = comb(n-1, k-1) + comb(n-1, k);
    return combination[n][k];
}

double prob_of_victory(double p, int n) {
    double total_prob = 0.0;
    for (int k = n; k <= 2*n-1; k++) {
        // probability of winning exactly k matches
        double prob = comb(2*n-1, k)*pow(p, k)*pow(1-p, 2*n-1-k);
        total_prob += prob;
    }
    return total_prob;
}

int main () {
    init_comb();

    cout << fixed;
    cout << setprecision(2);

    int ncases;
    cin >> ncases;
    while (ncases--) {
        int victories_needed;
        double prob;
        cin >> victories_needed;
        cin >> prob;
        cout << prob_of_victory(prob, victories_needed) << endl;
    }
    // cout << comb(49, 25) << endl;
    return 0;
}
