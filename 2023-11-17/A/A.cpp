#include <iostream>

#define PI  3.14159265358979323846

using namespace std;

int main() {
    double r;
    unsigned in, total;
    while ((cin >> r >> total >> in) && total)
        cout << (PI*r*r) << " " << (4*r*r)*((1.0*in)/total) << endl;
    return 0;
}
