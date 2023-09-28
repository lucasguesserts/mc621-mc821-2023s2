#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

int main() {
    auto a = double{0};
    auto b = double{0};
    auto c = double{0};
    auto d = double{0};
    cin >> a >> b >> c >> d;
    const auto a1 = a / b;
    const auto q = (1 - a / b) * (1 - c / d);
    const auto p = a1 / (1 - q);
    cout << std::setprecision(12) << fixed << p;
    return 0;
}
