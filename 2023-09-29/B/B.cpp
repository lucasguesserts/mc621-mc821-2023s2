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
