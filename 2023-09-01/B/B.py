if __name__ == "__main__":
    number_of_test_cases = int(input())
    for test_case_index in range(number_of_test_cases):
        number_of_days_in_a_year = int(input())
        n = 1
        probability_all_unique = [1]
        while (1 - probability_all_unique[-1] < 0.5):
            n += 1
            probability_all_unique.append(
                probability_all_unique[-1] * (1 - (n - 1) / number_of_days_in_a_year)
            )
        print("Case " + str(test_case_index + 1) + ": " + str(n - 1))
