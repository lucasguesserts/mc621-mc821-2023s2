/* https://codeforces.com/problemset/problem/755/A

Codeforces 755A - PolandBall and Hypothesis */

#define MAXM    1000

#include <stdio.h>

/* Ficaria mais rápido usando uma tabela de primos mas nem precisou... */
int primo(int num) {
    unsigned fator = 2;
    while (fator*fator <= num) {
        if (num % fator == 0)
            return 0;
        fator++;
    } 
    return 1;
}

unsigned contraexemplo(unsigned n) {
    unsigned m;
    unsigned candidato = n + 1;
    for (m = 1; m <= MAXM; m++, candidato += n)
        if (!primo(candidato))
            return m;
    return 0;
}

int main() {
    unsigned n;
    scanf("%u", &n);
    printf("%u\n", contraexemplo(n));
    return 0;
}
