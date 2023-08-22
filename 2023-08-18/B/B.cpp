#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main () {
    const auto max_exponent = std::floor(std::log2(std::numeric_limits<long int>::max()));
    long int n, m;
    long int result;
    cin >> n >> m;
    if (n > max_exponent) {
        result = m;
    } else {
        result = m % static_cast<long int>(round(pow(2, n)));
    }
    cout << result;
    return 0;
}
