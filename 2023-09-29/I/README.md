# [202 - Repeating Decimals](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5140)

The idea is to iteratively compute the remainder and the quotient of the division (literally, follow the division algorithm). When the remainder repeats, there the cycle begins. If, at some point, the remainder is zero, then it does not repeat.

To efficiently compute that, store the remainders seen so far in a map (key is the remainder, value is the index where it has last been seen). Also store all the quotients and mark where the decimal point is.
