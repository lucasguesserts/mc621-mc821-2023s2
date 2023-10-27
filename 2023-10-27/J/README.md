# [UVa - 11362 - Phone List](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2347)

1. get all strings in a list (vector in c++);
2. sort the list;
   1. notice that, if a number `x` is the prefix of another number `y`, then `x` comes right before `y` in the sorted list;
3. starting in the beginning of the list, check if the current number is in the next number;
   1. if it is, then the list is not consistent;
   2. if, for all numbers, it is not, then the list is consistent.
