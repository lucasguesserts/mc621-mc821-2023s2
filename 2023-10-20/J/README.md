# [Codeforces 520A - Pangram](https://codeforces.com/problemset/problem/520/A)

Simple enough solution: just check if every letter occurs in the string
(taking care to ignore case).

This could be achieved in many ways:

* add every found character to a set and then check the set for every letter;
* make every letter of the alphabet be a key in a frequency dictionary/map;
* do the same as the dictionary but with a 26 position array.