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
# [The 3n+1 Problem](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=36)

Straightforward problem, only requiring the correct calculation of the cycle
length of a given $n$.

Here we used an unordered map to store known cycle lengths, since in any
given sequence e.g.

$$ 22 \rightarrow 11 \rightarrow 34 \rightarrow 17 \rightarrow \cdots $$

if we have already encountered any of these successors, there is no need to
compute the whole sequence.

(Say we already knew that 11 has a cycle length of 15. Then 22 has a cycle
length of 16, which we find out after performing only one step rather than 16.)*/

// ==================== Code ====================

#include <cstdint>
#include <iostream>
#include <unordered_map>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

unordered_map<uint32_t, uint32_t> _cycle_length = {{1, 1}};

uint32_t cycle_length(uint32_t n) {
    if (!_cycle_length.count(n))
        _cycle_length[n] = 1 + cycle_length((n % 2) ? 3 * n + 1 : n / 2);
    return _cycle_length[n];
}

uint32_t max_cycle_length(uint32_t first, uint32_t last) {
    uint32_t ans = 0;
    for (int i = first; i <= last; i++)
        ans = MAX(ans, cycle_length(i));
    return ans;
}

int main() {
    uint32_t i, j;
    while (cin >> i >> j) {
        uint32_t start = MIN(i, j);
        uint32_t finish = MAX(i, j);
        cout << i << " " << j << " " << max_cycle_length(start, finish) << endl;
    }
    return 0;
}
