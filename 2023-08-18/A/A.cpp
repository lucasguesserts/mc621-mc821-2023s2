#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Transaction {
    string source;
    string target;
    int amount;
};

struct Account {
    string owner;
    int amount;
};

int main () {
    auto current_case_index = unsigned{0};

    while (true) {
        ++current_case_index;
        // variables
        auto travellers = vector<string>();
        auto transactions = vector<Transaction>();
        auto number_of_travellers = unsigned{};
        auto number_of_transactions = unsigned{};

        // input
        cin >> number_of_travellers >> number_of_transactions;
        if ((number_of_travellers == 0) && (number_of_transactions == 0)) break;
        for (auto i = 0u; i < number_of_travellers; ++i) {
            string traveller_name;
            cin >> traveller_name;
            travellers.push_back(traveller_name);
        }
        for (auto i = 0u; i < number_of_transactions; ++i) {
            Transaction transaction;
            cin >> transaction.source >> transaction.target >> transaction.amount;
            transactions.push_back(transaction);
        }

        // Solution
        auto balance = unordered_map<string, int>();
        for (const auto & traveller: travellers) {
            balance[traveller] = 0;
        }
        for (const auto & t: transactions) {
            balance[t.source] -= t.amount;
            balance[t.target] += t.amount;
        }
        auto v_balance = vector<Account>();
        for (const auto & x: balance) {
            v_balance.push_back({x.first, x.second});
        }
        sort(v_balance.begin(), v_balance.end(), [](const Account & lhs, const Account & rhs) { return lhs.amount < rhs.amount; });
        // for(auto & x: v_balance) {
        //     cout << x.owner << " " << x.amount << endl;
        // }
        auto reverse_transactions = vector<Transaction>();
        unsigned most_negative = 0;
        unsigned most_positive = v_balance.size() - 1;
        while (most_negative < most_positive) {
            auto reverse_transaction = Transaction();
            reverse_transaction.source = v_balance[most_positive].owner;
            reverse_transaction.target = v_balance[most_negative].owner;
            reverse_transaction.amount = min(v_balance[most_positive].amount, - v_balance[most_negative].amount);
            reverse_transactions.push_back(reverse_transaction);
            v_balance[most_positive].amount -= reverse_transaction.amount;
            v_balance[most_negative].amount += reverse_transaction.amount;
            if (v_balance[most_negative].amount == 0) ++most_negative;
            if (v_balance[most_positive].amount == 0) --most_positive;
        }

        cout << "Case #" << current_case_index << endl;
        for (const auto & reverse_transaction: reverse_transactions) {
            cout << reverse_transaction.source << " " << reverse_transaction.target << " " << reverse_transaction.amount << endl;
        }
        cout << endl;
    }
    return 0;
}
