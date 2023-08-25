#include <iostream>
#include <cstdint>
#include <cstdio>

#define MAXM    200000
#define MODULO  1000000007
#define MAXLEN  10

using namespace std;

uint64_t r[MAXM+1];

void compute_table() {
    int i;
    for (i = 0; i < 9; i++) r[i] = 2;
    r[9] = 3;
    for (i = 10; i <= MAXM; i++) r[i] = (r[i-9] + r[i-10]) % MODULO;
}

uint64_t compute_length(char *sequence, unsigned steps) {
    uint64_t total = 0;
    for (int i = 0; sequence[i]; i++) {
        unsigned digit = sequence[i] - '0';
        if (digit + steps < 10)
            total += 1;
        else
            total += r[(digit + steps) - 10];
        total = total % MODULO;
    }
    return total;
}

int main () {
    compute_table();
    unsigned ncases;
    cin >> ncases;
    while (ncases--) {
        char num[MAXLEN+1];
        unsigned m;
        scanf("%s %u", num, &m);
        cout << compute_length(num, m) << endl;
    }
    return 0;
}
