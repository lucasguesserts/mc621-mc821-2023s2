#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n, found;
        string in, big[2];
        cin >> n;
        for (int i = found = 0; i < 2*(n-1); i++) {
            cin >> in;
            if (in.size() == n-1)
                big[found++] = in;
        }
        cout << (big[0] == string(big[1].rbegin(), big[1].rend()) ? "YES" : "NO") << endl;
    }
    return 0;
}
