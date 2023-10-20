#include <stdio.h>

#define PLATESIZE   3
#define MAX_DICT    5000
#define MAXLEN      100

char dict[MAX_DICT][MAXLEN+1];
int dict_size;

int search_from(char c, char s[MAXLEN+1], int start) {
    int i;
    for (i = start; i < MAXLEN; i++)
        if (s[i] == c)
            return i;
    return MAXLEN;
}

int occurs(char plate[PLATESIZE+1], char s[MAXLEN+1]) {
    int i, start = 0;
    for (i = 0; i < PLATESIZE; i++) {
        start = 1 + search_from(plate[i], s, start);
        if (start > MAXLEN)
            return 0;
    }
    return 1;
}

int first_occurence(char plate[PLATESIZE+1]) {
    int i;
    for (i = 0; i < dict_size; i++)
        if (occurs(plate, dict[i]))
            return i;
    return -1;
}

void solve_case() {
    char plate[PLATESIZE+1];
    //fgets(plate, PLATESIZE+1, stdin);
    scanf("%s\n", &plate);
    int i;
    for (i = 0; i < PLATESIZE; i++)
        plate[i] = (char) (plate[i] - 'A') + 'a';
    i = first_occurence(plate);
    if (i < 0)
        printf("No valid word\n");
    else
        printf("%s\n", dict[i]);
}

int main() {
    int ntests;
    scanf("%d %d\n", &dict_size, &ntests);
    int i;
    for (i = 0; i < dict_size; i++)
        scanf("%s\n", &dict[i]);
    for (i = 0; i < ntests; i++)
        solve_case();
    return 0;
}
