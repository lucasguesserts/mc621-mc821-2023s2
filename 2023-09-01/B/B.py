"""
==================== LICENSE ====================

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

 ==================== Solution Description ====================

# [Birthday Paradox](https://lightoj.com/problem/birthday-paradox)

Let:
* `D`` be the number of days in a year;
* `n` be the number of people;

What is the probability that they all have different birthdays? For each person, we can compute the probability that it has an unique birthday:

| person number | probability it has unique birthday |
|---------------|------------------------------------|
| 0             | 1                                  |
| 1             | 1 - 1/D                            |
| ...           | ...                                |
| n - 1         | 1 - (n - 1) / D                    |

So what is the probability `P_u` that they all have unique birthdays? Simply multiply the probabilities above:

```plain
P_u = math.prod([1 - i/D for i in range(n)])
```

Now, what is the probability `P_s` that any two people have the same birthday? It is:

```plain
P_s = 1 - P_u = 1 - math.prod([1 - i/D for i in range(n)])
```

Finally, how do we find how many people we need to have `P_s > 0.5`. Simply try the values of `n` increasingly until you find the first which satisfy the required condition.

Notice that the question is: "how many people do you have to invite for the party so that `P_s > 0.5`?". It is already counting that you are going to be in the party, so output one less the value of `n` found.
"""

# ==================== Code ====================

if __name__ == "__main__":
    number_of_test_cases = int(input())
    for test_case_index in range(number_of_test_cases):
        number_of_days_in_a_year = int(input())
        n = 1
        probability_all_unique = [1]
        while 1 - probability_all_unique[-1] < 0.5:
            n += 1
            probability_all_unique.append(
                probability_all_unique[-1] * (1 - (n - 1) / number_of_days_in_a_year)
            )
        print("Case " + str(test_case_index + 1) + ": " + str(n - 1))
