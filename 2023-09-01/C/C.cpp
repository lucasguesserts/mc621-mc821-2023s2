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
# [What is the Probability?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=997)

First, notice that if $p = 0$ the problem becomes easy: no player has
any hope of winning, i.e. the probability is $0$ regardless of who is the
target player. Treat this case separately and assume $p > 0$ for the following
explanation.

There are infinitely many possible turns $1, 2, 3, \ldots$  in the game.
Turn $j$ is the winner with probability

$$ (1-p)^{j-1} p $$

i.e. it is necessary that the previous turns lose and $j$ wins. It is not
hard to verify that the sum of the above expression for every $j$ is 1, meaning
it makes sense as a probability function.

We have $N$ players, so for $i = {1, 2, \ldots, N}$, player $i$
wins if the winning turn is $i + kN$ for some integer $k\geq 0$.

Thus, defining $q := 1-p$, the probability of player $i$ winning is

$$
\begin{align*}
    \sum_{k \geq 0} (1-p)^{i + kN -1} p
        &= \sum_{k \geq 0} p(1-p)^{i-1}\left((1-p)^N\right)^k \\
        &= q^{i-1} (1-q) \sum_{k\geq 0} (q^N)^k \\
        &= \frac{q^{i-1}(1-q)}{1-q^N}
\end{align*}
$$

requiring only a straightforward implementation.
Remember once more that we are assuming $p > 0$ (and thus $1-q^N$ is nonzero).
*/

// ==================== Code ====================

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double prob_win(unsigned target, double p, unsigned n) {
    double q = 1 - p;
    return (p == 0.0) ? 0.0 : (pow(q, target - 1) * p) / (1 - pow(q, n));
}

int main() {
    int number_of_cases;
    cin >> number_of_cases;

    cout << fixed;
    cout << setprecision(4);

    while (number_of_cases--) {
        unsigned nplayers;
        double prob_success;
        unsigned desired_player;
        cin >> nplayers >> prob_success >> desired_player;
        cout << prob_win(desired_player, prob_success, nplayers) << endl;
    }
    return 0;
}
