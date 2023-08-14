#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using Number = unsigned int;
using Size = unsigned int;
using Sequence = vector<Number>;
using SequenceMap = map<Number, Sequence>;

struct Solver {

  SequenceMap sequence_map;

  Solver() {
    this->sequence_map[1] = {1};
    this->sequence_map[2] = {1, 2};
    return;
  }

  bool has_a_n_sum(const Sequence &sequence, const Number number) {
    for (auto &value_in_sequence : sequence) {
      const auto missing_value = number - value_in_sequence;
      if (binary_search(sequence.begin(), sequence.end(), missing_value)) {
        return true;
      }
    }
    return false;
  }

  Sequence get_smallest_sequence(const Number number) {
    Size smallest_sequence_size = 1000000000;
    Sequence smallest_sequence;
    for (Number k = 1; k < number; ++k) {
      const auto &k_sequence = this->solve(k);
      if (has_a_n_sum(k_sequence, number) &&
          (k_sequence.size() < smallest_sequence_size)) {
        smallest_sequence = k_sequence;
        smallest_sequence_size = k_sequence.size();
      }
    }
    return smallest_sequence;
  }

  const Sequence &solve(const unsigned number) {
    if (this->sequence_map.find(number) != this->sequence_map.end()) {
      return this->sequence_map[number];
    } else {
      auto smallest_sequence = this->get_smallest_sequence(number);
      smallest_sequence.push_back(number);
      this->sequence_map[number] = smallest_sequence;
      return this->sequence_map[number];
    }
  }
};

int main() {
  auto solver = Solver();
  Number number = 1;
  while(number != 0){
    cin >> number;
    const auto &sequence = solver.solve(number);
    for (const auto &value : sequence) {
      cout << value << " ";
    }
    cout << endl;
  }
  return 0;
}
