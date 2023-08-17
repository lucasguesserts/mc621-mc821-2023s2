#include <cstdio>
#include <map>
#include <utility>
#include <cinttypes>
 
#define MAXSIZE     (100000+1)
#define SQRTMAX     (316)
#define UNDEFINED   -1
#define max(a,b)    (((a) >= (b)) ? (a) : (b))
 
using namespace std;
 
unsigned tamanho_nivel[MAXSIZE];
uint64_t tabela[MAXSIZE][SQRTMAX+1];

int altura(int i, int *pais, int *alturas) {
    if (alturas[i] == UNDEFINED)
        alturas[i] = 1 + altura(pais[i], pais, alturas);
    return alturas[i];
}
 
int monta_arvore(int n, uint64_t *a, int *p, int *h) {
    int i, altura_maxima;
 
    // lê valores e inicializa alturas como UNDEFINED
    for (i = 0; i < n; i++) {
        unsigned valor;
        scanf("%d", &valor);
        a[i] = (uint64_t) valor;
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
 
uint64_t f(int x, int y, uint64_t *a, int *p, int *h, int *pos) {
    auto par = make_pair(x,y);
    int altura = h[x];
    if (tamanho_nivel[altura] <= SQRTMAX && tabela[x][pos[y]])
        return tabela[x][pos[y]];
    uint64_t res = a[x]*a[y] + f(p[x], p[y], a, p, h, pos);
    if (tamanho_nivel[altura] <= SQRTMAX)
        tabela[x][pos[y]]= res;
    return res;
}
 
int main() {
    int n, q, p[MAXSIZE], h[MAXSIZE], pos[MAXSIZE], altura_maxima;
    uint64_t a[MAXSIZE];
    scanf("%d %d", &n, &q);
 
    altura_maxima = monta_arvore(n, a, p, h);
    for (int i = 0; i <= altura_maxima; i++)
        tamanho_nivel[i] = 0;
    for (int i = 0; i < n; i++) pos[i] = tamanho_nivel[h[i]]++;

    // map<pair<int,int>,uint64_t> * t;
    // t = new map<pair<int,int>, uint64_t>[altura_maxima+1];
    // t[0][make_pair(0,0)] = a[0]*a[0];
    tabela[0][0] = a[0]*a[0];
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%" PRIu64 "\n", f(x-1,y-1, a, p, h, pos));
    }
 
}
