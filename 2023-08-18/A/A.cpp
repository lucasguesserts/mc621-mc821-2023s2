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
# [Balancing Bank Accounts](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=479)

First of all, one has to process the input and compute the balance of all accounts. The account of each traveller starts with `0` and changes with every transaction, and its total can be positive or negative.

To balance the accounts, one first sort them in non-descending order by their balance. The account with the biggest amount will be at the end while the one with the lowest will be at the beginning. Then one proceeds iteratively transfering money from the account with the largest amount to the one with the lowest so that at least one of them becomes zero. Such process can be done efficiently (at most `n - 1` transactions) with a sorted list.

## Note

The judge is quite annoying with the empty lines, so be sure that between the cases there is an empty line.
*/

// ==================== Code ====================

#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

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

int main() {
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
        for (const auto & traveller : travellers) {
            balance[traveller] = 0;
        }
        for (const auto & t : transactions) {
            balance[t.source] -= t.amount;
            balance[t.target] += t.amount;
        }
        auto v_balance = vector<Account>();
        for (const auto & x : balance) {
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
            reverse_transaction.amount = min(v_balance[most_positive].amount, -v_balance[most_negative].amount);
            reverse_transactions.push_back(reverse_transaction);
            v_balance[most_positive].amount -= reverse_transaction.amount;
            v_balance[most_negative].amount += reverse_transaction.amount;
            if (v_balance[most_negative].amount == 0) ++most_negative;
            if (v_balance[most_positive].amount == 0) --most_positive;
        }

        cout << "Case #" << current_case_index << endl;
        for (const auto & reverse_transaction : reverse_transactions) {
            cout << reverse_transaction.source << " " << reverse_transaction.target << " " << reverse_transaction.amount << endl;
        }
        cout << endl;
    }
    return 0;
}
