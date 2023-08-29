# [Birthday Paradox](https://lightoj.com/problem/birthday-paradox)

Let:
* `D`` be the number of days in a year;
* `n` be the number of people;

What is the probability that they all have different birthdays? For each person, we can compute the probability that it has an unique birthday:

| person number | probability it has unique birthday |
|---------------|------------------------------------|
| 0             | 1                                  |
| 1             | 1 - 1/D                            |
| ...           | ...                                |
| n - 1         | 1 - (n - 1) / D                    |

So what is the probability `P_u` that they all have unique birthdays? Simply multiply the probabilities above:

```plain
P_u = math.prod([1 - i/D for i in range(n)])
```

Now, what is the probability `P_s` that any two people have the same birthday? It is:

```plain
P_s = 1 - P_u = 1 - math.prod([1 - i/D for i in range(n)])
```

Finally, how do we find how many people we need to have `P_s > 0.5`. Simply try the values of `n` increasingly until you find the first which satisfy the required condition.

Notice that the question is: "how many people do you have to invite for the party so that `P_s > 0.5`?". It is already counting that you are going to be in the party, so output one less the value of `n` found.
