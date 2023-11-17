# [Kattis - Sticky Situation](https://open.kattis.com/problems/stickysituation)

Lenghts $a \leq b \leq c$ can be the sides of a proper triangle if, and only if,

$$ c < a + b .$$

To check whether our collection of sticks can form a proper triangle, we begin by sorting them by length.
Each stick starting from index 2 can be a candidate "big side" $c$. Any of the smaller sticks are possible
candidates for the small sides, but we only need to check the best candidates for the inequality above:
the sticks immediately smaller than it. (They are the biggest "small sides" available and thus if they
fail we know the others would fail as well.)

So we check wheter `stick[i] < stick[i-1] + stick[i-2]` for every stick `i` from `2` to `n-1`. 