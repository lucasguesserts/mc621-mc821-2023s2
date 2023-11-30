// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [Tree Master](https://codeforces.com/problemset/problem/1806/E)

This mostly just requires storing the tree and performing the described
computation algorithm efficiently enough.

The challenge here is the fact that for each instance there may be a large
number of queries. As such, and considering that `f(x,y)` is dependent on
`f(p(x),p(y))` i.e. the computation for the parents of `x` and `y`, we employ
memoization.

This requires having a table that stores for each `x` and `y` *that are on the
same level on the tree* the result of `f(x,y)` if it has already been
computed.

Moreover, we do *not* want to store pairs for a level of the tree if said level
has $\Theta(n)$ nodes, since this yields $\Theta(n^2)$ pairs, which is too costly.
A strategy that can be employed is to store pairs only of levels populated by
at most $\sqrt{n}$ nodes, resulting in $n$ pairs to be stored.

*/

// ==================== Code ====================

#include <cinttypes>
#include <cstdio>
#include <map>
#include <utility>

#define MAXSIZE (100000 + 1)
#define SQRTMAX (316)
#define UNDEFINED -1
#define max(a, b) (((a) >= (b)) ? (a) : (b))

using namespace std;

unsigned tamanho_nivel[MAXSIZE];
uint64_t tabela[MAXSIZE][SQRTMAX + 1];

int altura(int i, int * pais, int * alturas) {
    if (alturas[i] == UNDEFINED)
        alturas[i] = 1 + altura(pais[i], pais, alturas);
    return alturas[i];
}

int monta_arvore(int n, uint64_t * a, int * p, int * h) {
    int i, altura_maxima;

    // lê valores e inicializa alturas como UNDEFINED
    for (i = 0; i < n; i++) {
        unsigned valor;
        scanf("%d", &valor);
        a[i] = (uint64_t)valor;
        h[i] = UNDEFINED;
    }

    // lê pais, traduzindo label k como k-1
    p[0] = -1;
    for (i = 1; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }

    // calcula alturas
    altura_maxima = h[0] = 0;
    for (i = 1; i < n; i++) {
        h[i] = altura(i, p, h);
        altura_maxima = max(altura_maxima, h[i]);
    }
    return altura_maxima;
}

uint64_t f(int x, int y, uint64_t * a, int * p, int * h, int * pos) {
    auto par = make_pair(x, y);
    int altura = h[x];
    if (tamanho_nivel[altura] <= SQRTMAX && tabela[x][pos[y]])
        return tabela[x][pos[y]];
    uint64_t res = a[x] * a[y] + f(p[x], p[y], a, p, h, pos);
    if (tamanho_nivel[altura] <= SQRTMAX)
        tabela[x][pos[y]] = res;
    return res;
}

int main() {
    int n, q, p[MAXSIZE], h[MAXSIZE], pos[MAXSIZE], altura_maxima;
    uint64_t a[MAXSIZE];
    scanf("%d %d", &n, &q);

    altura_maxima = monta_arvore(n, a, p, h);
    for (int i = 0; i <= altura_maxima; i++)
        tamanho_nivel[i] = 0;
    for (int i = 0; i < n; i++)
        pos[i] = tamanho_nivel[h[i]]++;

    // map<pair<int,int>,uint64_t> * t;
    // t = new map<pair<int,int>, uint64_t>[altura_maxima+1];
    // t[0][make_pair(0,0)] = a[0]*a[0];
    tabela[0][0] = a[0] * a[0];
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%" PRIu64 "\n", f(x - 1, y - 1, a, p, h, pos));
    }
}
