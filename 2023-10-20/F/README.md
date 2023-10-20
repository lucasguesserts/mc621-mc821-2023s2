# [SPOJ IOIPALIN - Palindrome 2000](https://www.spoj.com/problems/IOIPALIN/)

Transforming a string into a palindrome can be viewed as a form of edit distance.

This problem can be solved by Needleman-Wunsch algorithm with appropriate scores for insertion, deletion,
match and mismatch.

The solution used here computes the LCS (based on Needleman-Wunsch) and substracts it from the
length of the original string to compute the needed additions.