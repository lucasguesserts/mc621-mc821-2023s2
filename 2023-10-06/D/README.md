# [Power Strings](https://open.kattis.com/problems/powerstrings)

A string $s$ is an $n^{\th}$ power if there is another string $b$ (its _base_)
such that $s = b^n$. For instance, the string $s = abababab$ can be expressed as
$(ab)^4$ or $(abab)^2$.

In this problem given $s$, our task is to find the maximum $n$ for
which $s$ is an $n^{th}$ power.

## An example

Consider the following example: `s = abcabcabc`. Imagine what would happen in
a search for `s` in itself: of course, there would be a match at index `0` and
the text would end. But if we could continue, the repetition contained in `s`
would cause "almost matches". In particular, imagine we extend `s` to `ss`
(or $s^2$, or in code `s+s`):

    ss = abcabcabcabcabcabc

Now if we were to search for `s` there, due the repetition of the pattern
(base) `abc`, there would be other matches. We would have $4$ matches, at
indices `0`, `3`, `6`, `9`; i.e. one for each start of the base `abc` in
the original string, plus an additional match in the second copy of `s`.

The additional match is not a beginning of the base in the original string
and thus should be discounted. Then, of the 4 matches above, 3 of them
indicate the start of a repeating pattern and thus we conclude that `s` is
some string (namely `abc`) repeated 3 times.

## Formalizing the idea and algorithm

Let $s = b^n$ for some string $b$ and some natural $n$.
Name the copies of $b$ in $s^2$ as

$$ s^2 = b_1 b_2 \cdots b_{n} b_{n+1} \cdots b_{2n} $$

where $b_1 = b_2 = \cdots = b_{2n} = b$.

Then, if we search for $s$ inside of $s^2$, there will be $n+1$ matches, namely
at the start of $b_1, b_2, \ldots, b_{n+1}$. The start of $b_{n+2}$ is not a match
because from then on the rest of the string is too short to match $s$ which is $n$
copies of $b$.

Thus, we to count every match of $s$
in $s^2$. We then have to discount one of these matches, as discussed above.
The counting can be done through KMP. Regular Expressions will not work because
they will only find two matches: at start of $b_1$ and $b_{n+1}$.
