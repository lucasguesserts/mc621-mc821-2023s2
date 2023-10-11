#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 2000000;

int b[MAX_N];

void kmpPreprocess(string P) {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < P.size()) {
        while ((j >= 0) && (P[i] != P[j]))
            j = b[j]; // different, reset j
        ++i;
        ++j;
        b[i] = j;
    }
}

unsigned kmpSearch(string P, string T) {
    int i = 0, j = 0,
        n = T.size(),
        m = P.size();
    unsigned matches = 0;
    while (i < n) {
        while ((j >= 0) && (T[i] != P[j]))
            j = b[j]; // if different, reset j
        ++i;
        ++j;
        if (j == m) {
            matches++; 
            j = b[j];
        }
    }
    return matches;
}

unsigned maximum_power(string s) {
    kmpPreprocess(s);
    return kmpSearch(s, s+s)-1;
}

int main() {
    string input;
    while ((cin >> input) && input[0] != '.')
        cout << maximum_power(input) << endl;
    return 0;
}
