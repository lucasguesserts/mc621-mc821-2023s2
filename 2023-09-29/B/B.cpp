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
# [Kattis - Party Game](https://open.kattis.com/problems/partygame)

The ideia is to implement the game and identify cycles using a hash.

1. Implement the game:
   1. Each lord has a Pin and a Card (each one is a number);
   2. Implement it using a map: pin -> card;
2. to identify cycles, create the hash of the current status;
   1. to know if there is a cycle, check if one has already seen the hash of the current status;
   2. to create a hash, take the pins of all lords, starting with the first lord of the map;
*/

// ==================== Code ====================

#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using I = std::size_t;

struct Lord {
    Lord(I pin, I card)
        : pin(pin)
        , card(card) {}
    const I pin;
    I card;
};
using VL = vector<Lord>;
using MII = map<I, I>; // pin -> card
using SI = set<I>;

void Match(MII & lords) {
    for (auto it = lords.begin(); it != lords.end();) {
        auto & pin = it->first;
        auto & card = it->second;
        if (pin == card) {
            it = lords.erase(it);
        } else {
            ++it;
        }
    }
    return;
}

void Snatch(MII & lords) {
    MII snatch;
    for (auto it = lords.begin(); it != lords.end(); ++it) {
        auto & pin = it->first;
        auto & card = it->second;
        snatch[pin] = lords[card];
    }
    snatch.swap(lords);
    return;
}

inline void hash_combine(I & seed, const I & v) {
    std::hash<I> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

I compute_hash(const MII & lords) {
    I first_pin = lords.begin()->first;
    I hash = first_pin;
    I pin = lords.begin()->second;
    while (pin != first_pin) {
        hash_combine(hash, pin);
        pin = lords.at(pin);
    }
    return hash;
}

int main() {
    I T;
    cin >> T;
    while (T--) {
        I n;
        MII lords;
        SI hashes;
        I current_hash = 0;
        // input
        cin >> n;
        for (I pin = 1; pin <= n; ++pin) {
            I card;
            cin >> card;
            lords[pin] = card;
        }
        // loop
        while (true) {
            Match(lords);
            Snatch(lords);
            if (lords.empty()) {
                cout << "All can eat." << endl;
                break;
            }
            I hash = compute_hash(lords);
            if (hashes.find(hash) != hashes.end()) {
                cout << "Some starve." << endl;
                break;
            }
            hashes.insert(hash);
        }
    }
    return 0;
}
