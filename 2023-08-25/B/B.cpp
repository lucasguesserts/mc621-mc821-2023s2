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
# [We Were Both Children](https://codeforces.com/problemset/problem/1850/F)

The simple idea is to simulate each frog's trajectory and update a counter
on each position it lands (ignoring position 0 and any positions past `n`).
We then select the position with most frog occurrences.

The above strategy gives the correct answer but can be too slow. Consider
an instance where every frog has the same hopping pattern. Our algorithm would
foolishly simulate every trajectory when they are the same.

We refine the idea by counting, for each possible hop pattern, how many
frogs have that pattern. For each hop distance we simulate the whole group
at once, again selecting the location with maximum frog landings.

*/

// ==================== Code ====================

#include <cstdio>

#define MAXN 200000

unsigned count[MAXN + 1];
unsigned frogs_with_hop[MAXN + 1];

void initialize(int n) {
    int i;
    for (i = 1; i <= n; i++)
        count[i] = frogs_with_hop[i] = 0;
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
