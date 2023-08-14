#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

using Number = long long unsigned int;
using ShortNumber = unsigned short;
using Digits = vector<ShortNumber>;

auto number_to_digits(Number number) -> Digits {
  auto digits = Digits();
  while (number != 0) {
    digits.push_back(number % 10);
    number /= 10;
  }
  reverse(digits.begin(), digits.end());
  return digits;
}

auto unluckyness(const Digits &digits) -> Number {
  const auto minimum = *min_element(digits.begin(), digits.end());
  const auto maximum = *max_element(digits.begin(), digits.end());
  return maximum - minimum;
}

int main() {
  auto number_of_test_cases = unsigned(0);
  cin >> number_of_test_cases;
  for (auto test_case_index = 0u; test_case_index < number_of_test_cases;
       ++test_case_index) {
    // input
    auto lower_bound = Number(0);
    auto upper_bound = Number(0);
    cin >> lower_bound >> upper_bound;
    // solution
    auto least_unluckyness = Number(10);
    auto unluckiest_number = Number(0);
    for (auto number = lower_bound; number <= upper_bound; ++number) {
      const auto digits = number_to_digits(number);
      const auto number_unluckyness = unluckyness(digits);
      if (number_unluckyness < least_unluckyness) {
        least_unluckyness = number_unluckyness;
        unluckiest_number = number;
      }
    }
    // output
    cout << unluckiest_number << endl;
  }
  return 0;
}
