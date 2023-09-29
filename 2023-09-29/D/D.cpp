#include <iostream>
#include <cstdint>
#include <unordered_map>

#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

using namespace std;

unordered_map<uint32_t, uint32_t> _cycle_length = { {1, 1} };

uint32_t cycle_length(uint32_t n) {
    if (!_cycle_length.count(n))
        _cycle_length[n] = 1 + cycle_length((n % 2) ? 3*n+1 : n/2);
    return _cycle_length[n];
}

uint32_t max_cycle_length(uint32_t first, uint32_t last) {
    uint32_t ans = 0;
    for (int i = first; i <= last; i++)
        ans = MAX(ans, cycle_length(i));
    return ans;
}

int main () {
    uint32_t i, j;
    while (cin >> i >> j) {
        uint32_t start = MIN(i, j);
        uint32_t finish = MAX(i, j);
        cout << i << " " << j << " " << max_cycle_length(start, finish) << endl;
    }
    return 0;
}
