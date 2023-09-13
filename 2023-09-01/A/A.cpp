#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    auto number_of_test_cases = unsigned(0);
    cin >> number_of_test_cases;
    for (auto test_case_index = 0u; test_case_index < number_of_test_cases; ++test_case_index) {
        auto number_of_integers = unsigned(0);
        cin >> number_of_integers;
        if (number_of_integers < 5u) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}
