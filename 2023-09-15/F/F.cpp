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
# [10179 - Irreducable Basic Fractions](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=1120&mosmsg=Submission+received+with+ID+28767712)

## The Real Problem

At first, the problem seems easy to solve: given $n \in \mathbb{N}$, take the numbers $[0, n - 1] \subset \mathbb{N}$ and remove the ones which are multiples of the prime factors of $n$.

Doing it by brute force is not viable, that would require too many computations. But one just need to count, and that seems easy too: given the prime factor $p$ of $n$, the quantity of number in $[0, n - 1]$ which are multiples of $p$ is $\left\lfloor \dfrac{n - 1}{p} \right\rfloor$. Thus, counting those and subtracting from $n-1$ is enough, right?

Unfortunately, no, it is not. Given two prime factors $p_x, p_y$, with such procedure one would subtract the multiples of $p_x p_y$ twice. But even if one considers that, given another prime factor $p_z$, the multiples of $p_x p_y p_z$ would not be counted (they would be removed twice).

The solution for the problem is simple: let $n = p_1^{e_1} \cdot \dots p_k^{e_k}$. Any time one gets an odd number of prime factors, one will subtract the number of multiples of the least common multiple. And any time one gets an even number of prime factors, one will add.

The idea is that with the odd we are discarding the multiples considered twice (but we are also discarding some multiples twice), and with the even we are correcting the calculation.

## Algorithm

Let $n \in \mathbb{N}$ as in the statement of the problem. The algorithm is as follows:

1. compute the prime factorization of $n$:

   $$ n = p_1^{e_1} \cdot \dots p_k^{e_k} $$

2. get the set of such prime numbers:

   $$ s = \{ p_1, \dots, p_k \} $$

3. get the power set of those prime numbers:

   $$ S = \mathcal{P}(s) $$

4. for each set of $S$, compute the signed number of multiples that the least common factor of the numbers in $s$ have up to $n-1$:

   $$ M = \{(-1)^{|s|} \ \left\lfloor \dfrac{n - 1}{lcm(s)} \right\rfloor : s \in S\} $$

   1. for the set $s = \{e_1, \dots, e_j\}$, we have $lcm(s) = lcm(e_1, \dots, e_j)$, the least common multiple of all elements of the set $s$;
   2. $(-1)^{|s|}$ is equals to $1$ when $s$ has an even number of elements, and $-1$ when it has an odd number of elements;
   3. $\left\lfloor \dfrac{x}{y} \right\rfloor$ is the number of multiples of $y$ smaller or equals $x$ that exist;
5. compute the number of irreducible basic fractions as:

   $$ c = n - 1 + \displaystyle\sum\limits_{m \in M} v $$

   1. $n$ because there are $n$ valid fractions;
   2. $-1$ because $\frac{1}{n}$ is not considered a irreducible basic fractions;
   3. the terms $m \in M$ correspont to the multiples of the prime factors of $n$;

Some boundary conditions:

1. if `n == 1`, give `1` as answer;
*/

// ==================== Code ====================

#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using Number = long unsigned int;
using PrimeFactorization = std::map<Number, Number>;

constexpr Number N_UPPER_BOUND = 1000000000;

auto gcd(const Number x, const Number y) -> Number {
    return y == 0 ? x : gcd(y, x % y);
}

auto lcm(const Number x, const Number y) -> Number { return x * y / gcd(x, y); }

auto power_set(const std::vector<Number> elements)
    -> std::vector<std::vector<Number>> {
    auto P = std::vector<std::vector<Number>>();
    P.push_back({});
    for (const auto e : elements) {
        auto temp = P;
        for (auto s : P) {
            s.push_back(e);
            temp.push_back(s);
        }
        P = temp;
    }
    return P;
}

auto sieve_of_erastothenes(const Number x) -> std::vector<Number> {
    auto numbers = std::vector<bool>(x, true);
    numbers[0] = false;
    numbers[1] = false;
    auto primes = std::vector<Number>();
    for (auto i = 2u; i < x; ++i) {
        if (numbers[i]) {
            primes.push_back(i);
            numbers[i] = false;
            for (auto j = i * i; j < x; j += i) {
                numbers[j] = false;
            }
        }
    }
    return primes;
}

auto prime_factorization(Number x, const std::vector<Number> primes)
    -> PrimeFactorization {
    auto factors = PrimeFactorization();
    for (const auto prime : primes) {
        if (x % prime == 0) {
            auto exponent = Number(0);
            while (x % prime == 0) {
                x /= prime;
                ++exponent;
            }
            factors[prime] = exponent;
        }
    }
    if (x != 1) {
        factors[x] = 1;
    }
    return factors;
}

auto count_multiples(const Number n, const std::vector<Number> numbers) -> Number {
    if (numbers.empty()) { return Number(0); }
    auto m = Number(1);
    for (const auto n : numbers) {
        m = lcm(m, n);
    }
    const auto count = static_cast<Number>(std::floor(n / m));
    return count;
}

auto solve(const Number n, const std::vector<Number> prime_factors) -> Number {
    if (n == 1) { return Number(1); }
    auto count = n;
    count -= 1; // remove 1 / n
    const auto P = power_set(prime_factors);
    for (const auto primes : P) {
        if (primes.size() % 2 == 0) {
            count += count_multiples(n - 1, primes);
        } else {
            count -= count_multiples(n - 1, primes);
        }
    }
    return count;
}

auto primes_of(const std::map<Number, Number> & factorization) -> std::vector<Number> {
    std::vector<Number> primes;
    for (const auto & factor : factorization) {
        primes.push_back(factor.first);
    }
    return primes;
}

int main() {
    auto n = Number(0);
    const auto primes = sieve_of_erastothenes(
        static_cast<Number>(std::floor(std::sqrt(N_UPPER_BOUND))));
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        const auto nf = prime_factorization(n, primes);
        const auto ps = primes_of(nf);
        cout << solve(n, ps) << endl;
    }
}
