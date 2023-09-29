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
