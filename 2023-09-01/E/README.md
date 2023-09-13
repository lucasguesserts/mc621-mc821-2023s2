# [1459A - Red-Blue Shuffle](https://codeforces.com/problemset/problem/1459/A)

This problem seems hard at first, and it would be if one had to compute the number of cases in which red or blue wins, but in the end that is not necessary. Notice that, if there are more cards in which the red number is bigger, then red has more chance of winning (if it is the blue, then blue has more chance). If, however, the number of cards for which the red number is bigger is the same as the number of cards for which the blue number is bigger, then their chances are equal. Finally, notice that cards in which the red and blue numbers are equal don't influence.

