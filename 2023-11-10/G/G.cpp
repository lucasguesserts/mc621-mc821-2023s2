#include <bits/stdc++.h>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

using I = int64_t;
using D = double;
using C = complex<D>;
constexpr D PI = 3.14159265358979323846264338327;

C rotate(C z, D degree) {
    D radian = PI * degree / 180;
    auto z_rotated = z * C(cos(radian), sin(radian));
    return z_rotated;
}

enum class CommandType {
    RotateLeft,
    RotateRight,
    WalkForward,
    WalkBackward,
};

auto string_2_command(const string & str) -> CommandType {
    if (str == "lt") {
        return CommandType::RotateLeft;
    } else if (str == "rt") {
        return CommandType::RotateRight;
    } else if (str == "fd") {
        return CommandType::WalkForward;
    } else if (str == "bk") {
        return CommandType::WalkBackward;
    } else {
        throw runtime_error("Unknown command string: " + str);
    }
}

constexpr D UNKNOWN_VALUE = NAN;

auto string_2_value(const string & str) -> D {
    if (str == "?") {
        return UNKNOWN_VALUE;
    }
    return stod(str);
}

class Command {
public:
    Command(const string & command_str, const string & value_str)
        : _type(string_2_command(command_str))
        , _value(string_2_value(value_str)) {}

    Command(CommandType type, D value)
        : _type(type)
        , _value(value) {}

    auto type() const -> CommandType {
        return this->_type;
    }

    auto value() const -> D {
        return this->_value;
    }

    auto reverse_command() const -> Command {
        switch (this->_type) {
        case CommandType::RotateLeft:
            return Command(CommandType::RotateRight, this->_value);
        case CommandType::RotateRight:
            return Command(CommandType::RotateLeft, this->_value);
        case CommandType::WalkForward:
            return Command(CommandType::WalkBackward, this->_value);
        case CommandType::WalkBackward:
            return Command(CommandType::WalkForward, this->_value);
        default:
            throw runtime_error("Unknown command type");
        }
    }

    auto make_from_unknown_value(D value) const -> Command {
        if (isnan(this->_value)) {
            return Command(this->_type, value);
        } else {
            throw runtime_error("This command is not unknown value");
        }
    }

private:
    CommandType _type;
    D _value;
};

class State {
public:
    State(C position, C angle)
        : _position(position)
        , _angle(angle) {}

    auto position() const -> C {
        return this->_position;
    }

    auto angle() const -> C {
        return this->_angle;
    }

    auto rotate_left(D degree) const -> State {
        auto new_angle = rotate(this->_angle, degree);
        auto new_state = State(this->_position, new_angle);
        return new_state;
    }

    auto rotate_right(D degree) const -> State {
        return this->rotate_left(-degree);
    }

    auto walk_forward(D distance) const -> State {
        auto displacement = this->_angle * distance;
        auto new_position = this->_position + displacement;
        auto new_state = State(new_position, this->_angle);
        return new_state;
    }

    auto walk_backward(D distance) const -> State {
        return this->walk_forward(-distance);
    }

    auto execute_command(const Command & command) const -> State {
        switch (command.type()) {
        case CommandType::RotateLeft:
            return this->rotate_left(command.value());
        case CommandType::RotateRight:
            return this->rotate_right(command.value());
        case CommandType::WalkForward:
            return this->walk_forward(command.value());
        case CommandType::WalkBackward:
            return this->walk_backward(command.value());
        default:
            throw runtime_error("Unknown command type");
        }
    }

    auto distance(const State & other) const -> D {
        return abs(this->_position - other._position);
    }

    auto displace(C displacement) const -> State {
        auto new_position = this->_position + displacement;
        auto new_state = State(new_position, this->_angle);
        return new_state;
    }

private:
    C _position;
    C _angle;
};

using Cit = vector<Command>::const_iterator;

auto find_state(State state, Cit begin, Cit end) -> State {
    while (begin != end) {
        const auto & command = *begin;
        state = state.execute_command(command);
        ++begin;
    }
    return state;
}

constexpr D TOLERANCE = 1e-6;

auto binary_search(
    const State & reference_state,
    const State & state_before_unknown,
    const C & displacement,
    const Command & unknown_command,
    D lower_bound,
    D upper_bound)
    -> D {
    auto final_state = state_before_unknown;
    auto value = 0;
    while (reference_state.distance(final_state) > TOLERANCE) {
        State lower_state = state_before_unknown;
        {
            auto state = state_before_unknown;
            state = state.execute_command(unknown_command.make_from_unknown_value(lower_bound));
            state = state.displace(displacement);
            lower_state = state;
        }
        State upper_state = state_before_unknown;
        {
            auto state = state_before_unknown;
            state = state.execute_command(unknown_command.make_from_unknown_value(upper_bound));
            state = state.displace(displacement);
            upper_state = state;
        }
        auto lower_distance = reference_state.distance(lower_state);
        auto upper_distance = reference_state.distance(upper_state);
        if (lower_distance < upper_distance) {
            upper_bound = (lower_bound + upper_bound) / 2;
            final_state = lower_state;
            value = lower_bound;
        } else {
            lower_bound = (lower_bound + upper_bound) / 2;
            final_state = upper_state;
            value = upper_bound;
        }
    }
    return value;
}

int main() {
    I T;
    cin >> T;
    while (T--) {
        // read commands
        I number_of_commands;
        cin >> number_of_commands;
        vector<Command> commands;
        for (I i = 0; i < number_of_commands; ++i) {
            string command_str;
            string value_str;
            cin >> command_str >> value_str;
            commands.push_back(Command(command_str, value_str));
        }
        // find unknown command
        I unknown_command_position = -1;
        for (I i = 0; i < number_of_commands; ++i) {
            if (isnan(commands[i].value())) {
                unknown_command_position = i;
                break;
            }
        }
        // define state before the unknown command
        const auto reference_state = State(C(0, 0), C(1, 0));
        auto state_before_unknown = find_state(reference_state, commands.cbegin(), commands.cbegin() + unknown_command_position);
        auto displacement_state = find_state(state_before_unknown, commands.cbegin() + unknown_command_position + 1, commands.cend());
        const auto & unknown_command = commands[unknown_command_position];
        auto answer = binary_search(
            reference_state,
            state_before_unknown,
            displacement_state.position(),
            unknown_command,
            0,
            100000);
        cout << round(answer);
    }
    return 0;
}
