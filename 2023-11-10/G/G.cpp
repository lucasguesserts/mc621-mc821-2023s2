#include <bits/stdc++.h>
#include <cmath>
#include <stdexcept>
#include <string>

// thanks to BrandonTang89 who wrote a nice description of their algorithm
// https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_7_Computational_Geometry/Basic_Geometry_Objects_with_Libraries/kattis_logo2.cpp

using namespace std;

using I = int64_t;
using D = double;
using C = complex<D>;
constexpr D PI = 3.14159265358979323846264338327;

struct Vector {
    array<C, 2> data;

    Vector(C a0, C a1)
        : data{a0, a1} {}

    auto to_string() -> string {
        string result;
        result += "[";
        result += std::to_string(data[0].real()) + " + " + std::to_string(data[0].imag()) + "j";
        result += ", ";
        result += std::to_string(data[1].real()) + " + " + std::to_string(data[1].imag()) + "j";
        result += "]";
        return result;
    }
};

struct Matrix {
    array<array<C, 2>, 2> data;

    Matrix() {
        *this = identity();
    };

    Matrix(C a00, C a01, C a10, C a11) {
        data[0][0] = a00;
        data[0][1] = a01;
        data[1][0] = a10;
        data[1][1] = a11;
    }

    auto to_string() -> string {
        string result;
        result += "[";
        result += "\n";
        result += "\t";
        result += std::to_string(data[0][0].real()) + " + " + std::to_string(data[0][0].imag()) + "j";
        result += ", ";
        result += std::to_string(data[0][1].real()) + " + " + std::to_string(data[0][1].imag()) + "j";
        result += "\n";
        result += "\t";
        result += std::to_string(data[1][0].real()) + " + " + std::to_string(data[1][0].imag()) + "j";
        result += ", ";
        result += std::to_string(data[1][1].real()) + " + " + std::to_string(data[1][1].imag()) + "j";
        result += "\n";
        result += "]";
        return result;
    }

    auto invert() -> void {
        auto & a = this->data;
        C det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        auto tmp = decltype(this->data)();
        tmp[0][0] = a[1][1] / det;
        tmp[1][1] = a[0][0] / det;
        tmp[0][1] = -a[0][1] / det;
        tmp[1][0] = -a[1][0] / det;
        this->data = tmp;
        return;
    }

    static auto identity() -> Matrix {
        return Matrix(C(1, 0), C(0, 0), C(0, 0), C(1, 0));
    }

    static auto rotation(D degree) -> Matrix {
        D radian = PI * degree / 180.0;
        return Matrix(C(1, 0), C(0, 0), C(0, 0), C(cos(radian), sin(radian)));
    }

    static auto displacement(D value) -> Matrix {
        return Matrix(C(1, 0), C(value, 0), C(0, 0), C(1, 0));
    }
};

auto operator*(const Matrix & lhs, const Matrix & rhs) -> Matrix {
    Matrix X;
    auto & x = X.data;
    const auto & l = lhs.data;
    const auto & r = rhs.data;
    x[0][0] = l[0][0] * r[0][0] + l[0][1] * r[1][0];
    x[0][1] = l[0][0] * r[0][1] + l[0][1] * r[1][1];
    x[1][0] = l[1][0] * r[0][0] + l[1][1] * r[1][0];
    x[1][1] = l[1][0] * r[0][1] + l[1][1] * r[1][1];
    return X;
}

auto operator*(const Matrix & M, const Vector & V) {
    const auto & m = M.data;
    const auto & v = V.data;
    array<C, 2> c;
    c[0] = m[0][0] * v[0] + m[0][1] * v[1];
    c[1] = m[1][0] * v[0] + m[1][1] * v[1];
    return Vector(c[0], c[1]);
}

struct Command {

    static constexpr D UNKNOWN_VALUE = NAN;

    enum class Type {
        RotateLeft,
        RotateRight,
        WalkForward,
        WalkBackward,
    };

    auto string_2_command(const string & str) -> Type {
        if (str == "lt") {
            return Type::RotateLeft;
        } else if (str == "rt") {
            return Type::RotateRight;
        } else if (str == "fd") {
            return Type::WalkForward;
        } else if (str == "bk") {
            return Type::WalkBackward;
        } else {
            throw runtime_error("Unknown command string: " + str);
        }
    }

    auto string_2_value(const string & str) -> D {
        if (str == "?") {
            return UNKNOWN_VALUE;
        }
        return stod(str);
    }

    Command() = default;

    Command(const string & command_str, const string & value_str)
        : type(string_2_command(command_str))
        , value(string_2_value(value_str)) {}

    Command(Type type, D value)
        : type(type)
        , value(value) {}

    auto is_unknown() const -> bool {
        return isnan(this->value);
    }

    auto matrix() -> Matrix {
        switch (this->type) {
        case Type::RotateLeft:
            return Matrix::rotation(this->value);
        case Type::RotateRight:
            return Matrix::rotation(-this->value);
        case Type::WalkForward:
            return Matrix::displacement(this->value);
        case Type::WalkBackward:
            return Matrix::displacement(-this->value);
        default:
            throw runtime_error("Unknown command type");
        }
    }

public:
    Type type;
    D value;
};

int main() {
    I T;
    cin >> T;
    while (T--) {
        // read data
        I number_of_commands;
        cin >> number_of_commands;
        Matrix B;
        Command command_unknown;
        Matrix A;
        bool unknown_found = false;
        for (I i = 0; i < number_of_commands; ++i) {
            string command_str;
            string value_str;
            cin >> command_str >> value_str;
            auto command = Command(command_str, value_str);
            if (command.is_unknown()) {
                unknown_found = true;
                command_unknown = command;
                continue;
            }
            if (unknown_found) {
                A = command.matrix() * A;
            } else {
                B = command.matrix() * B;
            }
        }
        // solve
        const auto initial_position = Vector(C(0, 0), C(1, 0));
        constexpr D TOLERANCE = 1e-6;
        int correct_angle = -1;
        auto final_position = Vector(C(0, 0), C(1, 0));
        switch (command_unknown.type) {
        case Command::Type::RotateLeft:
        case Command::Type::RotateRight:
            for (int a = 0; a <= 359; ++a) {
                auto command = command_unknown;
                command.value = a;
                auto M = A * command.matrix() * B;
                final_position = M * initial_position;
                if ((abs(final_position.data[0].real()) < TOLERANCE) && (abs(final_position.data[0].imag()) < TOLERANCE)) {
                    correct_angle = a;
                    break;
                }
            }
            cout << correct_angle;
            break;
        case Command::Type::WalkForward:
        case Command::Type::WalkBackward:
            final_position = A * B * initial_position;
            cout << abs(final_position.data[0]);
            break;
        default:
            throw runtime_error("Unknown command type");
        }
        cout << endl;
    }
    return 0;
}
