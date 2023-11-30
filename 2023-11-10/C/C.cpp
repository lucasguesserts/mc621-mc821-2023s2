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
# [Kattis - Support Vector Machine](https://open.kattis.com/problems/svm)

There is no particular trick to this one; just implement the distance formula attentively:

$$ d(x) = \frac{(w^T x + b)}{\| w \|} $$

where $w$ is the given vector which is orthonormal to the hyperplane and $b$ is the offset from the origin.

We have to correctly implement:

* inner (dot) product $x^T y$ between vectors $x, y$ of same dimension;
* norm of a vector $y$ which is $\sqrt{y^T y}$;
* reading vectors for the hyperplane and queries;
* reading queries until `EOF` occurs. Here, we use `cin.ignore(1)` to dismiss newline symbols and `cin.peek()` to check whether the next character is `EOF`.*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

struct vec {
    vector<double> coords;
    unsigned dimension;

    vec(vector<double> _coords)
        : coords(_coords)
        , dimension(_coords.size()) {}
    vec(vector<double> _coords, unsigned _dimension)
        : coords(_coords)
        , dimension(_dimension) {}
};

struct hyperplane {
    vec orthogonal_vector;
    double offset;

    hyperplane(vec orth, double offs)
        : orthogonal_vector(orth)
        , offset(offs) {}
};

double dot(vec x, vec y) {
    int n = x.dimension;
    double res = 0.0;
    for (int i = 0; i < n; i++)
        res += x.coords[i] * y.coords[i];
    return res;
}

double norm(vec x) {
    return sqrt(dot(x, x));
}

double dist_vec_hyperplane(vec x, hyperplane h) {
    return (h.offset + dot(x, h.orthogonal_vector)) / norm(h.orthogonal_vector);
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

int main() {
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
