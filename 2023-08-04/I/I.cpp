#include <iostream>
#include <vector>
#include <algorithm>

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
