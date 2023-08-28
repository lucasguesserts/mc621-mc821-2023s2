#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    auto B = int(1);
    auto S = int(1);
    auto count = int(0);
    while (true) {
        ++count;
        cin >> B >> S;
        if ((B == 0) && (S == 0)) {
            break;
        }
        cout << "Case " << count << ": ";
        if (B == 1) {
            cout << ":-\\" << endl;
            continue;
        }
        auto probability_before = min(double(S) / B, 1.0);
        auto probability_after = min(double(S - 1) / (B - 1), 1.0);
        if (probability_after > probability_before) {
            cout << ":-)" << endl;
        } else if (probability_after < probability_before) {
            cout << ":-(" << endl;
        } else {
            cout << ":-|" << endl;
        }
    }
    return 0;
}
