def compute_final_position(command_list):
    position = 0
    for command in command_list:
        if command == "+":
            position += 1
        elif command == "-":
            position -= 1
        else:
            continue
    return position

def compute_prob(n, k):
    acc = 1
    for i in range(k):
        acc *= (n - i)
        acc //= (i + 1)
    return acc / (2 ** n)

def probability(initial_position, final_position, number_of_steps):
    diff = final_position - initial_position
    if abs(diff) > number_of_steps: return 0.0
    positives = diff if diff >= 0 else 0
    steps_to_sum_zero = number_of_steps - abs(diff)
    if steps_to_sum_zero % 2 != 0: return 0.0
    positives += steps_to_sum_zero // 2
    return compute_prob(number_of_steps, positives)

if __name__ == "__main__":
    commands_sent = input()
    expected_position = compute_final_position(commands_sent)
    commands_received = input()
    middle_expected_position = compute_final_position(commands_received)
    number_of_unknowns = commands_received.count("?")
    print("{:.12f}".format(probability(middle_expected_position, expected_position, number_of_unknowns)))
