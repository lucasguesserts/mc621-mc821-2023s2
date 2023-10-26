# [Kattis - Suffix Sorting](https://open.kattis.com/problems/suffixsorting)

It is ALMOST the Suffix Array, but in this problem, they want to sort the suffix, and not the cyclic shift.

To really solve the problem, one must add a terminal character to the string. That character must be one smaller than any other character in the input strings. One chose `\n` for that purpose (`$` cannot be used because ` ` (space) is smaller).

