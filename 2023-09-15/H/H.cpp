#include <algorithm>
#include <iostream>

using Number = long long unsigned int;

struct Pair {
  Number high;
  Number low;

  Pair(const Number high, const Number low)
      : high(high), low(low) {}

  auto operate_set_high() -> void {
    const auto diff = this->diff();
    if (diff >= this->low) {
        this-> high = diff;
    } else {
        this-> high = this->low;
        this->low = diff;
    }
    return;
  }

  auto is_valid(const Number target) const -> bool {
    return this->high > target;
  }

  auto meets_target(const Number target) const -> bool {
    return (this->high == target) || (this->low == target);
  }

  auto diff() const -> Number { return this->high - this->low; }
};

struct Xmagic {
  Xmagic(const Number a, const Number b, const Number x)
      : high(std::max(a, b)), low(std::min(a, b)), target(x), pair(high, low),
        solution_found(false){};

  auto solve() -> void {
    while (true) {
      if (pair.meets_target(this->target)) {
        this->solution_found = true;
        break;
      }
      if (!pair.is_valid(this->target)) {
        break;
      }
      this->pair.operate_set_high();
    }
    return;
  }

  const Number high;
  const Number low;
  const Number target;
  Pair pair;
  bool solution_found;
};

int main() {
  auto number_of_test_cases = Number(0);
  std::cin >> number_of_test_cases;
  for (auto test_case_index = Number(0); test_case_index < number_of_test_cases;
       ++test_case_index) {
    auto a = Number(0);
    auto b = Number(0);
    auto x = Number(0);
    std::cin >> a >> b >> x;
    auto magic = Xmagic(a, b, x);
    magic.solve();
    const auto answer = magic.solution_found ? "YES" : "NO";
    std::cout << answer << std::endl;
  }
  return 0;
}
