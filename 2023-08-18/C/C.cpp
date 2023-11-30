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
# [Bmail Computer Network](https://codeforces.com/problemset/problem/1057/A)

1. Create the graph;
2. Find the path from the last node to the first node;
3. Reverse the path;
*/

// ==================== Code ====================

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unsigned number_of_routers;
    auto parent = unordered_map<unsigned, unsigned>{};

    // input
    cin >> number_of_routers;
    parent[1] = 0;
    for (auto i = 2u; i <= number_of_routers; ++i) {
        auto parent_router = unsigned{0};
        cin >> parent_router;
        parent[i] = parent_router;
    }

    // solve
    auto router = number_of_routers;
    auto path = vector<unsigned>{router};
    while (router != 1) {
        router = parent[router];
        path.push_back(router);
    }
    reverse(path.begin(), path.end());

    // output
    for (const auto & router : path) {
        cout << router << " ";
    }

    return 0;
}
