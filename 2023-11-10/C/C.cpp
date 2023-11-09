#include <bits/stdc++.h>

using namespace std;

struct vec {
    vector<double> coords;
    unsigned dimension;

    vec(vector<double> _coords) : coords(_coords), dimension(_coords.size()) {}
    vec(vector<double> _coords, unsigned _dimension) : coords(_coords), dimension(_dimension) {}
};

struct hyperplane {
    vec orthogonal_vector;
    double offset;

    hyperplane(vec orth, double offs) : orthogonal_vector(orth), offset(offs) {}
};

double dot(vec x, vec y) {
    int n = x.dimension;
    double res = 0.0;
    for (int i = 0; i < n; i++)
        res += x.coords[i]*y.coords[i];
    return res;
}

double norm(vec x) {
    return sqrt(dot(x, x));
}

double dist_vec_hyperplane(vec x, hyperplane h) {
    return (h.offset + dot(x, h.orthogonal_vector))/norm(h.orthogonal_vector);
}

vec read_vec(unsigned dimension) {
    vector<double> coordinates;
    coordinates.reserve(dimension);
    while (dimension--) {
        double value;
        cin >> value;
        coordinates.push_back(value);
    }
    return vec(coordinates);
}

int main () {
    int n;
    double b;

    cin >> n;
    vec w = read_vec(n);
    cin >> b;
    
    hyperplane h(w, b);

    cin.ignore(1); // ignore \n
    while (cin.peek() != EOF) {
        cout << dist_vec_hyperplane(read_vec(n), h) << endl;
        cin.ignore(1);
    }

    return 0;
}
