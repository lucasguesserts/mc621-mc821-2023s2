# [Quite a Problem](https://open.kattis.com/problems/quiteaproblem)

This problem asks us to read each line independently and then decide whether
it contains the word `PROBLEM` regardless of case.

We can simply use the KMP algorithm:

* We run the preprocessing with pattern `P = "PROBLEM"`
* We modify the algorithm itself to ignore case (in this code, we simply
compare each pair of characters in their upper case versions using the
function `toupper`)
