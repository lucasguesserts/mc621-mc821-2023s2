#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

using Number = long unsigned int;

// class SieveOfErastothenes

struct PrimeFactoration {
  PrimeFactoration(const Number N) {
    Number X = N;
    for (const auto &prime : PRIME_NUMBERS_TILL_1000) {
      if (X % prime == 0) {
        Number exponent = 0;
        while (X % prime == 0) {
          X /= prime;
          ++exponent;
        }
        this->factors[prime] = exponent;
      }
    }
  };

  static auto reduce(const Number lhs, const Number rhs) -> Number {
    return lhs < rhs ? Number(0) : lhs - rhs;
  }

  std::map<Number, Number> factors; // key is the prime, value is its exponent
  static const std::vector<Number> PRIME_NUMBERS_TILL_1000;
};

const std::vector<Number> PrimeFactoration::PRIME_NUMBERS_TILL_1000{
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
    47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
};

struct Rational {
  Rational(PrimeFactoration numerator, PrimeFactoration denominator) {
    // reduce the factors
    for (auto it = numerator.factors.begin(); it != numerator.factors.end();) {
      const auto factor = *it;
      const auto prime = factor.first;
      const auto exponent = factor.second;
      if (denominator.factors.count(prime) > 0) {
        numerator.factors[prime] =
            PrimeFactoration::reduce(exponent, denominator.factors[prime]);
        denominator.factors[prime] =
            PrimeFactoration::reduce(denominator.factors[prime], exponent);
        if (numerator.factors[prime] == 0) {
          it = numerator.factors.erase(it);
        } else {
            ++it;
        }
        if (denominator.factors[prime] == 0) {
          denominator.factors.erase(prime);
        }
      } else {
        ++it;
      }
    }
    // compute numerator
    this->numerator = 1;
    for (const auto &factor : numerator.factors) {
      for (auto i = 0u; i < factor.second; ++i) {
        this->numerator *= factor.first;
      }
    }
    // compute denominator
    this->denominator = 1;
    for (const auto &factor : denominator.factors) {
      for (auto i = 0u; i < factor.second; ++i) {
        this->denominator *= factor.first;
      }
    }
    return;
  }

  auto to_string() -> std::string {
    return std::to_string(this->numerator) + "/" +
           std::to_string(this->denominator);
  }

  Number numerator;
  Number denominator;
};

int main() {
  // data
  auto N = Number(0);
  vector<Number> R;
  // input
  cin >> N;
  for (auto i = 0u; i < N; ++i) {
    auto r = Number(0);
    cin >> r;
    R.push_back(r);
  }
  // solution
  const auto r0f = PrimeFactoration(R[0]);
  auto solution = std::vector<Rational>();
  for (auto i = 1u; i < N; ++i) {
    const auto r = R[i];
    const auto rf = PrimeFactoration(r);
    solution.push_back(Rational(r0f, rf));
  }
  // output
  for (auto i = 0u; i < N - 1; ++i) {
    cout << solution[i].to_string() << endl;
  }
  return 0;
}
