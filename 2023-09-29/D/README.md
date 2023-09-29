# [The 3n+1 Problem](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=36)

Straightforward problem, only requiring the correct calculation of the cycle
length of a given $n$.

Here we used an unordered map to store known cycle lengths, since in any
given sequence e.g.

$$ 22 \rightarrow 11 \rightarrow 34 \rightarrow 17 \rightarrow \cdots $$

if we have already encountered any of these successors, there is no need to
compute the whole sequence.

(Say we already knew that 11 has a cycle length of 15. Then 22 has a cycle
length of 16, which we find out after performing only one step rather than 16.)