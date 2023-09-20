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
