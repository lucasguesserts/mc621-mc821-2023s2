#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    auto x = unsigned{0};
    cin >> x;
    auto current_2_factor = unsigned{0};
    current_2_factor = static_cast<unsigned>(pow(2, floor(log2(x))));
    auto number_of_bacterias = unsigned{0};
    while (x != 0) {
        if (x >= current_2_factor) {
            ++number_of_bacterias;
            x -= current_2_factor;
        }
        current_2_factor /= 2;
    }
    cout << number_of_bacterias;
    return 0;
}
