#include <iostream>

using namespace std;

unsigned get_number_of_cases() {
    unsigned n;
    cin >> n;
    return n;
}

char * get_case_input() {
    auto c = new char[3];
    cin >> c[0] >> c[1] >> c[2];
    return c;
}

bool is_yes(const char * const c) {
    const bool y = c[0] == 'Y' || c[0] == 'y';
    const bool e = c[1] == 'E' || c[1] == 'e';
    const bool s = c[2] == 'S' || c[2] == 's';
    return y && e && s;
}

int main() {
    const unsigned n = get_number_of_cases();
    for (auto i = 0u; i < n; ++i) {
        const auto c = get_case_input();
        if (is_yes(c)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}