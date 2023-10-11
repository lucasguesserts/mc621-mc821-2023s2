#include <iostream>
#include <string>

#define MAX_N   100

using namespace std;

void kmpPreprocess(string P, int * b) {
    int i = 0, j = -1, m = P.size();
    b[0] = -1;
    while (i < m) {
        while ((j >= 0) && (P[i] != P[j]))
            j = b[j]; // different, reset j
        ++i;
        ++j;
        b[i] = j;
    }
}

bool kmpSearch(string P, string T, int * b) {
    int i = 0, j = 0,
        m = P.size(),
        n = T.size();
    while (i < n) {
        while ((j >= 0) && (toupper(T[i]) != toupper(P[j])))
            j = b[j]; // if different, reset j
        ++i;
        ++j;
        if (j == m)
            return true;
    }
    return false;
}

int main() {
    int table[MAX_N];
    string pattern = "PROBLEM";
    kmpPreprocess(pattern, table);

    string line;
    while (getline(cin, line))
        cout << (kmpSearch(pattern, line, table) ? "yes" : "no") << endl;
}

