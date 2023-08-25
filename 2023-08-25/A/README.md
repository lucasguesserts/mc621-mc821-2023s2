# [Krakovia](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1866)

The solution to this problem is to sum every entry in the group of friends' tab
at the bar, obtaining a total~$T$, and outputting the truncated result of
$T/F$, with $F$ being the number of friends.

The only obstacle is that the tab entries might be large numbers, and so we
are required to deal with big integers in some way. Solutions in Python
with its native `int` type, in Java with its `BigInt`, or C++ with a custom
big integer solution, should all work fine.
