# [Kattis cargame - Car Game](https://open.kattis.com/problems/cargame)

This is more straightforward than it might look. Our task is to:

* Read the dictionary words, storing them in order (we want to output the first match, so the order matters);
* For each license plate, search for the first dictionary word that it is a subsequence to.

The second step should *NOT* be done via a classic LCS solution, because it will exceed time limit.

Since the pattern we are searching for is very well-behaved (just a three-character string), a "manual"
search will suffice.

___

Beware of problems regarding the newline (`\n`) character when reading in C or C++.