#include <iostream>
#include <cstdint>

using namespace std;

/*
   Prints a representation of k in base 9 with a custom digit set.
   Digits       0, 1, 2, 3, 5, 6, 7, 8, 9
   represent    0, 1, 2, 3, 4, 5, 6, 7, 8
   respectively.
*/
void show_number(uint64_t k) {
    unsigned rep[16];
    unsigned size = 0;
    while (k) {
        unsigned digit = k % 9; 
        rep[size++] = (digit < 4)? digit : digit+1;
        k /= 9;
    }
    while (size) cout << rep[--size];
    cout << endl;
}

int main () {
    unsigned ncases;
    cin >> ncases;
    while (ncases--) {
        uint64_t k;
        cin >> k;
        show_number(k);
    }
    return 0;
}
