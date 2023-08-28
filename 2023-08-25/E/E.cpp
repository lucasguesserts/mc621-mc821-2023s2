#include <iostream>

#define MAXLEN  5

using namespace std;

unsigned positive_combinations(char pattern[MAXLEN+1], int start) {
    if (!pattern[start]) return 1;
    char c = pattern[start];
    unsigned this_position = 1;
    if (c == '?') this_position = (start) ? 10 : 9;
    else if (c == '0' && !start) return 0;
    return this_position*positive_combinations(pattern, start+1);
}

int main () {
    int ncases;
    char input[MAXLEN+1];
    cin >> ncases;
    while (ncases--) {
        cin >> input;
        cout << positive_combinations(input, 0) << endl;
    }
    return 0;
}
