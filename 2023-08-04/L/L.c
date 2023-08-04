#include <stdio.h>

#define MAXSIZE 100000
#define LENGTH  11

int play(char *seq, int size) {
    int turns = (size-LENGTH)/2;
    int i, j;
    for (i = j = 0; turns; turns--) {
        while (i < size && (seq[i] == '8' || seq[i] == 0)) i++;
        if (i == size) return 1;
        seq[i] = 0;

        while (j < size && seq[j] != '8') j++;
        if (j == size) return 0;
        seq[j] = 0;
    }
    for (i = 0; i < size && !seq[i]; i++);
    return seq[i] == '8';
}

int main() {
    int n;
    char sequence[MAXSIZE];
    scanf("%d\n%s", &n, sequence);
    if (play(sequence, n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

