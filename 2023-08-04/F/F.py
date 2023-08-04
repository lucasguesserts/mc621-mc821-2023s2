def compute_final_position(command_list):
    position = 0
    for command in command_list:
        if command == "+":
            position += 1
        elif command == "-":
            position -= 1
        else:
            raise Exception("Invalid command")
    return position

def compute_middle_position(command_list):
    valid_commands = filter(lambda x: x != "?", command_list)
    return compute_final_position(valid_commands)

def dfs_binary_tree(uncertainty_counter, position, probability, probability_map):
    if uncertainty_counter == 0:
        probability_map[position] = probability_map.get(position, 0) + probability
    else:
        dfs_binary_tree(uncertainty_counter - 1, position + 1, probability / 2, probability_map)
        dfs_binary_tree(uncertainty_counter - 1, position - 1, probability / 2, probability_map)
    return

if __name__ == "__main__":
    commands_sent = input()
    expected_position = compute_final_position(commands_sent)
    commands_received = input()
    middle_expected_position = compute_middle_position(commands_received)
    probability_map = {}
    dfs_binary_tree(commands_received.count("?"), middle_expected_position, 1, probability_map)
    print("{:.12f}".format(probability_map.get(expected_position, 0)))

