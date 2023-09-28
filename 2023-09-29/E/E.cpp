#include <iostream>
#include <cstdint>
#include <string>

#define PERIOD  100

using namespace std;

uint32_t lastdigit[PERIOD];

uint32_t last_digit_pow(uint32_t base, uint32_t exp) {
    if (exp == 0) return 1;
    uint32_t aux = last_digit_pow(base, exp/2);
    if (exp % 2)
        return (aux*aux*base % 10);
    return (aux*aux % 10);
}

void compute_sequence() {
    lastdigit[0] = 0;   // artificial definition; matches lastdigit[100] which is size of period
    for (int i = 1; i < PERIOD; i++)
        lastdigit[i] = (last_digit_pow(i, i) + lastdigit[i-1]) % 10;
}

int main() {
    compute_sequence();
    string in;
    while ((cin >> in) && in != "0") {
        uint32_t n = 0, mult = 1, size = in.size();
        for (int i = 1; i <= size && i <= 2; mult *= 10, i++)
            n += (in[size-i] - '0')*mult;
        cout << lastdigit[n] << endl;
    }
    return 0;
}
