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
