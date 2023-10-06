#include <iostream>
#include <string>
#include <vector>

using namespace std;

using I = long long int;
using VI = vector<I>;

I find(string & s, VI & v, char c, I b) {
    for (I i = s.size() - 1; i > b; --i) {
        if (s[i] == c)
            if (v[i] < v[b])
                return i;
    }
    return I(-1);
}

void opt(string & s, VI & v) {
    for (I i = 0; i < s.size(); ++i) {
        char c = s[i];
        I p = find(s, v, c, i);
        if (p != -1) {
            swap(v[i], v[p]);
        }
    }
    return;
}

I bubble_sort(VI & arr) {
    // https://www.geeksforgeeks.org/bubble-sort-in-cpp/
    I i, j;
    I n = arr.size();
    I count = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    I n, count;
    string s;
    cin >> n;
    cin >> s;
    VI v(n);
    for (I i = 0; i < n; ++i) {
        v[i] = n - i - 1;
    }
    opt(s, v);
    cout << bubble_sort(v);
    return 0;
}
