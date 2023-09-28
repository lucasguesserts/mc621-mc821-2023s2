#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double prob_win(unsigned target, double p, unsigned n) {
    double q = 1 - p;
    return (p == 0.0) ? 0.0 : (pow(q, target - 1) * p) / (1 - pow(q, n));
}

int main() {
    int number_of_cases;
    cin >> number_of_cases;

    cout << fixed;
    cout << setprecision(4);

    while (number_of_cases--) {
        unsigned nplayers;
        double prob_success;
        unsigned desired_player;
        cin >> nplayers >> prob_success >> desired_player;
        cout << prob_win(desired_player, prob_success, nplayers) << endl;
    }
    return 0;
}
