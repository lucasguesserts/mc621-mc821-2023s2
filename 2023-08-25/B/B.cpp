#include <cstdio>
 
#define MAXN    200000
 
unsigned count[MAXN+1];
unsigned frogs_with_hop[MAXN+1];
 
void initialize(int n) {
    int i;
    for (i = 1; i <= n; i++) count[i] = frogs_with_hop[i] = 0;
}
 
void treat_case() {
    int n;
    scanf("%d", &n);
    initialize(n);
    
    for (int frog = 1; frog <= n; frog++) {
        unsigned hopsize;
        scanf("%u", &hopsize);
        if (hopsize <= n)
            frogs_with_hop[hopsize] += 1;
    }
 
    unsigned max = 0;
    for (unsigned hopsize = 1; hopsize <= n; hopsize++) {
        for (int j = hopsize; j <= n; j += hopsize) {
            count[j] += frogs_with_hop[hopsize];
            if (count[j] > max)
                max = count[j];
        }
    }
 
    printf("%u\n", max);
}
 
int main() {
    int ntests;
    scanf("%d", &ntests);
    while (ntests--) {
        treat_case();
    }
    return 0;
}

