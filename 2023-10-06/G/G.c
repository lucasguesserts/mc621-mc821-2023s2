#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 1000000

void solve (char s[SIZE], char sub[SIZE]) {
    bool found_at_least_one = false;
    int count = 0;
    int shift = 0;
    int positions[SIZE];
    int i;
    positions[0] = 0;
    while (true) {
        char * p = strstr(s, sub);
        if (p == NULL) break;
        found_at_least_one = true;
        positions[count] = p - s + 1 + shift;
        positions[count + 1] = 0;
        shift += (p - s) + strlen(sub);
        s += (p - s) + strlen(sub);
        ++count;
    }
    if (found_at_least_one) {
        printf("%d\n", count);
        for (i = 0; positions[i] != 0; ++i) {
            printf("%d ", positions[i]);
        }
    } else {
        printf("Not Found");
    }
    printf("\n");
    return;
}

int main () {
    int ncases;
    char s[SIZE], sub[SIZE];
    scanf("%d", &ncases);
    while (ncases--) {
        scanf("%s\n%s", s, sub);
        solve(s, sub);
        printf("\n");
    }
    return 0;
}
