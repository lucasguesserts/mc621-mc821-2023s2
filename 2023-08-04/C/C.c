#include <stdio.h>
 
#define MAXN    4
#define MAXK    5
#define MAXF    256  /* > 3^5 */
#define BLACK   '*'
#define WHITE   '.'
 
int pot(int b, int e) { return (e == 0) ? 1 : b*pot(b, --e); }
 
void drawBlack(char fig[MAXF][MAXF], int tam, int r, int c) {
    int i, j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++)
            fig[r + i][c + j] = BLACK;
    }
}
 
void drawFigure(char pat[MAXN][MAXN], int n, int k,
                char fig[MAXF][MAXF], int r, int c) {
    int i, j, offset, sr, sc;
    if (k == 1) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                fig[i + r][j + c] = pat[i][j];
        }
        return;
    }
    offset = pot(n, k-1);
    sr = r;
    for (i = 0; i < n; i++) {
        sc = c;
        for (j = 0; j < n; j++) {
            if (pat[i][j] == BLACK)
                drawBlack(fig, offset, sr, sc);
            else
                drawFigure(pat, n, k-1, fig, sr, sc);
            sc += offset;
        }
        sr += offset;
    }
}
 
FILE * out;
 
void printFractal(char pattern[MAXN][MAXN], int n, int k) {
    char figure[MAXF][MAXF];
    int i, sz;
    sz = pot(n, k);
    for (i = 0; i < sz; i++)
        figure[i][sz] = '\0';
    drawFigure(pattern, n, k, figure, 0, 0);
    for (i = 0; i < sz; i++)
        printf("%s\n", figure[i]);
}
 
int main() {
    char pattern[MAXN][MAXN];
    int i, n, k;
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        scanf(" %s", pattern[i]);
 
    printFractal(pattern, n, k);
    return 0;
}
