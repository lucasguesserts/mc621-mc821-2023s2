# [UVa 13146 - Edid Tistance](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5057)

Given an integer `t`, we are given `t` pair of strings.

For each pair $A, B$, we need to output the *edit distance* $d(A,B)$ between
$A$ and $B$.

This is a classic problem that can be solved using the Needleman-Wunsch algorithm
for string alignment. Chosing the scores

* Insertion and deletion: -1;
* Mismatch: -1;
* Match: 0;

Then the optimal value of string alignment between $A$ and $B$ will be $-d(A,B)$.

___

Beware of how the input should be read.
Depending on how you read the first line (number of test cases), you might get
an empty string if you try to get the first string using `getline()`. I wasn't
patient enough to think of an elegant solution to this and simply asked
`scanf()` to "eat" the `\n` for me.