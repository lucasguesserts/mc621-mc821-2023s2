# [We Were Both Children](https://codeforces.com/problemset/problem/1850/F)

The simple idea is to simulate each frog's trajectory and update a counter
on each position it lands (ignoring position 0 and any positions past `n`).
We then select the position with most frog occurrences.

The above strategy gives the correct answer but can be too slow. Consider
an instance where every frog has the same hopping pattern. Our algorithm would
foolishly simulate every trajectory when they are the same.

We refine the idea by counting, for each possible hop pattern, how many
frogs have that pattern. For each hop distance we simulate the whole group
at once, again selecting the location with maximum frog landings.

