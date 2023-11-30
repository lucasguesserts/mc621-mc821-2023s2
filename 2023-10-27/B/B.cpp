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
# [Kattis - Suffix Sorting](https://open.kattis.com/problems/suffixsorting)

It is ALMOST the Suffix Array, but in this problem, they want to sort the suffix, and not the cyclic shift.

To really solve the problem, one must add a terminal character to the string. That character must be one smaller than any other character in the input strings. One chose `\n` for that purpose (`$` cannot be used because ` ` (space) is smaller).

*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

vector<int> sort_cyclic_shifts(string const & s) {
    // function that takes a string $s$ and returns the permutations of the sorted cyclic shifts
    // O(n log n) time
    // O(n) space
    int n = s.size();
    const int alphabet = 256;
    //
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    //
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

int main() {
    string s, ns;
    int m;
    vector<int> q;
    while (true) {
        // input
        getline(cin, s);
        if (cin.eof()) {
            break;
        }
        s += "\n";
        getline(cin, ns);
        stringstream ss(ns);
        ss >> m;
        q.clear();
        q.reserve(m);
        for (int i = 0; i < m; ++i) {
            int x;
            ss >> x;
            q.push_back(x);
        }
        // solution
        auto p = sort_cyclic_shifts(s);
        p.erase(p.begin());
        for (int i = 0; i < m; ++i) {
            cout << p[q[i]] << " ";
        }
        cout << endl;
        // output
    }
}
