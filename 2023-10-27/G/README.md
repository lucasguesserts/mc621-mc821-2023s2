# [UVa 760 - DNA Sequencing](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=701)

Use the DP algorithm for the Longest Common Subsequence problem (links below). However, instead of storing only the size of the substring, store the substring itself. Once the solution has been found, use the naive algorithm: go through all the table and find all subsequences that have the same size as the largest one. Store the subsequences in a set, so duplicates are ignored and the sequence is sorted.

## Links

* [geek for geek - Longest Common Subsequence](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/);
* [wikipedia - Longest Common Subsequence](https://en.wikipedia.org/wiki/Longest_common_subsequence);
