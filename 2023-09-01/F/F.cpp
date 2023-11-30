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
# [Tennis contest](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3888)

If we have $n$ trials of an event with probability $p$, the probability of
having *exactly* $k$ successes is

$$ p(n, k) = \binom{n}{k} p^k (1-p)^{n-k} $$

as we need $k$ successes, $n-k$ failures and there are $\binom{n}{k}$ orders
in which this may happen.

In this problem, we are interested in the following question: what is the
probability of having *at least* $n$ successes from $2n-1$ trials?

The answer is

$$ \sum_{k=n}^{2n-1} p(2n-1, k) $$

where $p(2n-1, k)$ is computed by the expression given in the beginning.

To make this fast, we memorize the already known binomial coefficients.
*/

// ==================== Code ====================

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

#define MAXN 25

using namespace std;
using value_t = uint64_t;

value_t combination[2 * MAXN][2 * MAXN + 1] = {};

void init_comb() {
    for (int i = 0; i < 2 * MAXN; i++) {
        combination[i][0] = combination[i][i] = 1;
    }
}

// returns n choose k
value_t comb(int n, int k) {
    if (!combination[n][k])
        combination[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
    return combination[n][k];
}

double prob_of_victory(double p, int n) {
    double total_prob = 0.0;
    for (int k = n; k <= 2 * n - 1; k++) {
        // probability of winning exactly k matches
        double prob = comb(2 * n - 1, k) * pow(p, k) * pow(1 - p, 2 * n - 1 - k);
        total_prob += prob;
    }
    return total_prob;
}

int main() {
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
