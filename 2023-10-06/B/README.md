# [Is It a Cat?](https://codeforces.com/problemset/problem/1800/A)

In this problem, we are required to decide, for each string given as input,
if it is a _meow_. A _meow_ is a string matching the regular expression


    ^[Mm]+[Ee]+[Oo]+[Ww]+$


such as `meow`, `mmMmmmEoWWW` etc.

Fittingly, the most economical solution in terms of code is to use regular
expression search.
