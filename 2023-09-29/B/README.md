# [Kattis - Party Game](https://open.kattis.com/problems/partygame)

The ideia is to implement the game and identify cycles using a hash.

1. Implement the game:
   1. Each lord has a Pin and a Card (each one is a number);
   2. Implement it using a map: pin -> card;
2. to identify cycles, create the hash of the current status;
   1. to know if there is a cycle, check if one has already seen the hash of the current status;
   2. to create a hash, take the pins of all lords, starting with the first lord of the map;
