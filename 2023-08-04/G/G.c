#include <stdio.h>
#include <limits.h>
#include <string.h>
 
#define INFINITY    INT_MAX
#define MAXLEN      12
#define MAX         26
#define max(a,b)    (a > b) ? a : b
 
int main() {
    int n, m, first, last, len, i, j;
    char name[MAXLEN];
 
    /* maxD[i][j] == tamanho máximo de dinastia começando com a letra i + 'a'
       e terminando com a letra j + 'a'. */
    int maxD[MAX][MAX];
 
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            maxD[i][j] = -INFINITY;
 
    for (scanf("%d", &n); n; n--) {
        scanf("%s", name);
        len = strlen(name);
        first = name[0] - 'a';
        last = name[len-1] - 'a';
        for (i = 0; i < MAX; i++)
            maxD[i][last] = max(maxD[i][first] + len, maxD[i][last]);
        maxD[first][last] = max(maxD[first][last], len);
    }
 
    /* As dinastias realmente válidas são as que começam e terminam com a mesma
    letra. Assim, procuramos o máximo na diagonal da tabela. */
    m = 0;
    for (i = 0; i < MAX; i++)
        m = max(maxD[i][i], m);
    printf("%d\n", m);
    return 0;
}
