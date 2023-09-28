#include <iostream>

using namespace std;

using N = long long int;

int main() {
    N t;
    cin >> t;
    while (t--) {
        N n = -1LL; // number of friends
        N b = -1LL; // number of box of chocolates
        cin >> n >> b;
        N C = 0LL; // number of chocolates (total)
        while (b--) {
            N c = 1LL; // number of chocolates in this box
            N k = 0LL;
            cin >> k;
            while (k--) {
                N a = 1LL; // a_i indicates the number of boxes the i-th box contains within it
                cin >> a;
                c *= a;
                c %= n;
            }
            C += c;
            C %= n;
        }
        cout << C % n << endl;
    }
    return 0;
}
