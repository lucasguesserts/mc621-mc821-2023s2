#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using Number = long long unsigned int;

struct Pair {
  const Number high;
  const Number low;
  const bool can_set_low_flag;

  Pair(const Number high, const Number low, const bool can_set_low_flag)
      : high(std::move(high)), low(std::move(low)),
        can_set_low_flag(can_set_low_flag) {}

  auto operate_set_low() const -> Pair {
    const auto new_pair = Pair(this->high, this->diff(), false);
    return new_pair;
  }

  auto operate_set_high() const -> Pair {
    const auto diff = this->diff();
    if (diff >= this->low) {
      const auto new_pair = Pair(diff, this->low, true);
      return new_pair;
    } else {
      const auto new_pair = Pair(this->low, diff, true);
      return new_pair;
    }
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
      : high(std::max(a, b)), low(std::min(a, b)), target(x), queue(),
        solution_found(false), solution(nullptr) {
    this->queue.push(Pair(this->high, this->low, true));
    return;
  };

  auto solve() -> void {
    while (!queue.empty()) {
      const auto pair = this->get_next();
      if (pair.meets_target(this->target)) {
        this->solution_found = true;
        this->solution = new Pair(pair);
      }
      if (!pair.is_valid(this->target)) {
        continue;
      }
      this->step(pair);
    }
    return;
  }

  const Number high;
  const Number low;
  const Number target;
  std::queue<Pair> queue;
  bool solution_found;
  Pair *solution;

  auto get_next() -> Pair {
    const auto pair = this->queue.front();
    this->queue.pop();
    return pair;
  }

  auto step(const Pair &pair) -> void {
    this->queue.push(pair.operate_set_high());
    if (pair.can_set_low_flag) {
      this->queue.push(pair.operate_set_low());
    }
    return;
  }
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
