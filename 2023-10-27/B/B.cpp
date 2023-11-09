#include <bits/stdc++.h>
#include <sstream>

using namespace std;

vector<int> sort_cyclic_shifts(string const& s) {
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
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
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
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

int main () {
    string s, ns;
    int m;
    vector<int> q;
    while (true) {
        // input
        getline(cin, s);
        if (cin.eof()) {
            break;
        }
        s += "\b";
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
