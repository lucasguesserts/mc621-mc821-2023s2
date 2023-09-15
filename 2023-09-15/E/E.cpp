#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

using Number = long unsigned int;

constexpr Number NUMBER_OF_PRIMES = 168;

constexpr std::array<Number, NUMBER_OF_PRIMES> PRIMES{
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

auto is_noldbach_prime(const Number i) {
  for (auto j = 0u; j < i - 1; ++j) {
    if (PRIMES[j] + PRIMES[j + 1] + 1 == PRIMES[i]) {
      return true;
    }
  }
  return false;
}

auto count_noldbach_primes(const Number n, const Number k, const std::vector<bool> noldbach_primes) {
  auto i = Number(1);
  auto count = Number(0);
  while (PRIMES[i] <= n) {
    if (noldbach_primes[i]) {
      ++count;
    }
    ++i;
  }
  return count;
}

int main() {
  // pre-processing
  std::vector<bool> noldbach_primes;
  noldbach_primes.push_back(false);
  for (auto i = 1u; i < NUMBER_OF_PRIMES; ++i) {
    noldbach_primes.push_back(is_noldbach_prime(i));
  }
  // data
  auto n = Number(0);
  auto k = Number(0);
  // input
  cin >> n;
  cin >> k;
  // solution
  const auto number_of_noldback_numbers = count_noldbach_primes(n, k, noldbach_primes);
  // output
  if (number_of_noldback_numbers >= k) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
