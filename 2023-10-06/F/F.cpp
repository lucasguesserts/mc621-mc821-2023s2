#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

using I = long long int;

const string simon = "Simon says";

int main () {
    I N;
    string s;
    scanf("%lld\n", &N);
    while (N--) {
        getline(cin, s);
        I p = s.find(simon);
        if (p == -1) continue;
        string command(s.begin() + simon.size(), s.end());
        cout << command << endl;
    }
    return 0;
}
