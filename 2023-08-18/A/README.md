# [PROBLEM_NAME](PROBLEM_LINK)

First of all, one has to process the input and compute the balance of all accounts. The account of each traveller starts with `0` and changes with every transaction, and its total can be positive or negative.

To balance the accounts, one first sort them in non-descending order by their balance. The account with the biggest amount will be at the end while the one with the lowest will be at the beginning. Then one proceeds iteratively transfering money from the account with the largest amount to the one with the lowest so that at least one of them becomes zero. Such process can be done efficiently (at most `n - 1` transactions) with a sorted list.

## Note

The judge is quite annoying with the empty lines, so be sure that between the cases there is an empty line.
