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
# [Codeforces 1430E - String Reversal](https://codeforces.com/problemset/problem/1430/E)

Consider the string `s = abcafag` (as an example).

1. map where each character should be in the reverse string:
   1. `[6, 5, 4, 3, 2, 1, 0]`;
2. for each char, find the last position where it occurs and swap them;
   1. (the technique described here is way too slow, but that is the basic idea);
   2. character `a`: `[6, 5, 4, 3, 2, 1, 0]` $\rightarrow$ `[1, 5, 4, 3, 2, 6, 0]`;
3. compute how many swap operations a sort needs;
*/

// ==================== Code ====================

// https://codeforces.com/blog/entry/83614

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using li = long long int;

const int N = 200 * 1000 + 13;

int n;
string s;
string revS;
vector<int> posS[30];
vector<int> posT[30];
int cnt[30];
int t[N];

inline int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        result += t[r];
    return result;
}

inline void inc(int i, int d) {
    for (; i < n; i = (i | (i + 1)))
        t[i] += d;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

inline void solve() {
    revS = s;
    reverse(revS.begin(), revS.end());
    for (int i = 0; i < s.size(); i++) {
        posS[s[i] - 'a'].push_back(i);
        posT[revS[i] - 'a'].push_back(i);
    }
    li ans = 0;
    for (int i = 0; i < revS.size(); i++) {
        int let = revS[i] - 'a';
        int cur = posS[let][cnt[let]];
        int oldC = cur;
        cur += sum(cur, n - 1);
        int need = i;
        ans += cur - need;
        inc(oldC, 1);
        cnt[let]++;
    }
    cout << ans;
}

int main() {
    cin >> n >> s;
    solve();
}
