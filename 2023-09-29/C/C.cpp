#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;

using I = int64_t;
using S = string;

class F {
public:
    virtual I operator()(I x) = 0;
    virtual ~F() {}
};

class Func : public F {
public:
    Func(I N)
        : N(N)
        , spec(get_spec()) {}

    static vector<S> get_spec() {
        vector<S> spec;
        string s;
        getline(cin, s);
        stringstream ss(s);
        S op;
        while (ss >> op) {
            spec.push_back(op);
        }
        if (spec.back() == "%") {
            spec.pop_back();
        }
        if (spec.back() == "N") {
            spec.pop_back();
        }
        return spec;
    }

    virtual I operator()(I x) override {
        I a, b;
        stack<I> s;
        for (auto op : this->spec) {
            if (op == "+") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push((a + b) % N);
            } else if (op == "*") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push((a * b) % N);
            } else if (op == "%") {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b % a);
            } else if (op == "x") {
                s.push(x);
            } else if (op == "N") {
                s.push(this->N);
            } else {
                s.push(stoll(op));
            }
        }
        x = s.top();
        s.pop();
        if (!s.empty()) {
            throw runtime_error("stack is not empty");
        }
        return x;
    }

private:
    const I N;
    const vector<S> spec;
};

class SuperFunc : public F {
public:
    SuperFunc(F * const f, I n)
        : n(n), f(f) {
            this->v.push_back((*this->f)(this->n));
        }

    virtual I operator()(I k) override {
        k = k - 1; // 0-indexed
        if (this->v.size() > k) {
            return this->v[k];
        }
        else {
            for (I i = this->v.size(); i <= k; ++i) {
                this->v.push_back((*this->f)((*this)(i)));
            }
        }
        return this->v[k];
    }

private:
    const I n;
    F * const f;
    vector<I> v;
};

void floyd_cycle_finding(F & f, I x0, I & mu, I & lambda) {
    // 1st part: finding k*mu, hare's speed is 2x tortoise’s
    I tortoise_x = x0 + 1;
    I tortoise = f(tortoise_x);
    I hare_x = x0 + 2;
    I hare = f(hare_x); // f(x0) is the node next to x0
    while (tortoise != hare) {
        tortoise_x += 1;
        tortoise = f(tortoise_x);
        hare_x += 2;
        hare = f(hare_x);
    }
    // 2nd part : finding mu, hare and tortoise move at the same speed
    mu = 0;
    tortoise_x = x0;
    tortoise = f(tortoise_x);
    while (tortoise != hare) {
        tortoise_x += 1;
        tortoise = f(tortoise_x);
        hare_x += 1;
        hare = f(hare_x);
        ++mu;
    }
    // 3rd part : finding lambda , hare moves , tortoise stays
    lambda = 1;
    hare_x = tortoise_x + 1;
    hare = f(hare_x);
    while (tortoise != hare) {
        hare_x += 1;
        hare = f(hare_x);
        ++lambda;
    }
    return;
}

void see(F & f, I L) {
    cout << "=== SEE ===" << endl;
    for (I i = 1; i < L; ++i) {
        cout << i << " -> " << f(i) << endl;
    }
    cout << "=== END SEE ===" << endl;
    return;
}

int main() {
    I N, n;
    while (true) {
        cin >> N >> n;
        if (N == 0) {
            break;
        }
        F * f = new Func(N);
        F * sf = new SuperFunc(f, n);
        I mu, lambda;
        // see(*sf, 1000);
        floyd_cycle_finding(*sf, 1, mu, lambda);
        cout << lambda << endl;
        delete(f);
    }
    return 0;
}
