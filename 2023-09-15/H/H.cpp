#include <algorithm>
#include <cmath>
#include <iostream>

using Number = long long int;

bool solve(Number high, Number low, Number target) {
    if (high == target || low == target) {
        return true;
    }
    if (high < low) {
        std::swap(high, low);
    }
    low = std::min(low, high - low);
    if (target > std::max(high, low) || high == 0 || low == 0) {
        return false;
    }
    Number k = std::max(Number(1), (high - std::max(target, low)) / low);
    return solve(high - low * k, low, target);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        Number a, b, x;
        std::cin >> a >> b >> x;
        if (solve(a, b, x)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
