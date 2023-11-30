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
# [Game with Cards](https://codeforces.com/problemset/problem/1681/A)

The solution of this problem is simple: the one who has the card with the highest number wins. In case of a tie, the one who starts the game wins.
*/

// ==================== Code ====================

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using Cards = vector<unsigned>;

unsigned get_one_number() {
    unsigned n;
    cin >> n;
    return n;
}

Cards get_cards(const unsigned number_of_cards) {
    Cards cards;
    cards.reserve(number_of_cards);
    for (auto i = 0u; i < number_of_cards; ++i) {
        unsigned card;
        cin >> card;
        cards.push_back(card);
    }
    return cards;
}

void print_cards(const Cards & cards) {
    for (const auto card : cards) {
        cout << card << ' ';
    }
    cout << endl;
}

bool does_first_player_wins(const Cards & first_player_cards, const Cards & second_player_cards) {
    const auto first_player_maximum_card_number = *max_element(first_player_cards.cbegin(), first_player_cards.cend());
    const auto second_player_maximum_card_number = *max_element(second_player_cards.cbegin(), second_player_cards.cend());
    return first_player_maximum_card_number >= second_player_maximum_card_number;
}

int main() {
    const unsigned number_of_cases = get_one_number();
    for (auto case_number = 0u; case_number < number_of_cases; ++case_number) {
        const unsigned alice_number_of_cards = get_one_number();
        const auto alice_cards = get_cards(alice_number_of_cards);
        const unsigned bob_number_of_cards = get_one_number();
        const auto bob_cards = get_cards(bob_number_of_cards);
        if (does_first_player_wins(alice_cards, bob_cards)) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
        if (does_first_player_wins(bob_cards, alice_cards)) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}
