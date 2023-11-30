// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [1612 - D - X-Magic Pair](https://codeforces.com/problemset/problem/1612/D)

## Definitions

For all this documentation, consider the pair $p$ of values as being composed of a high value $h \in \mathbb{Z}_+$, the first one, and a low value $l \in \mathbb{Z}_+$, the second one:

$$ p = \left\langle h, l \right\rangle \in \mathbb{Z}_+ \times \mathbb{Z}_+$$

## About the Operations

(Note that $\left|h - l\right| = \left|l - h\right| = h - l$).

There are two operations:

* **Operation L**: replace $l$ by $h - l$;
* **Operation H**: replace $h$ by $h - l$;

Let's see what we get from each one of them.

### Opearation L

$$
\left\langle h, l \right\rangle
\rightarrow
\left\langle h, h - l \right\rangle
\rightarrow
\begin{cases}
    \left\langle h, h - (h - l) \right\rangle = \left\langle h, l \right\rangle, \text{Operation L}\\
    \left\langle h - (h - l), h - l \right\rangle = \left\langle l, h - l \right\rangle, \text{Operation H} \land l \geqslant h - l\\
    \left\langle h - l, h - (h - l) \right\rangle = \left\langle h - l, l \right\rangle, \text{Operation H} \land l < h - l
\end{cases}
$$

Thus, there are three values we may get:

1. $\left\langle h, l \right\rangle$
2. $\left\langle l, h - l \right\rangle$, if $l \geqslant h - l$
3. $\left\langle h - l, l \right\rangle$, if $l < h - l$

Notice that the first one does not interest us because it is the original pair. Also, the last two values are the same, with the difference being the order of the values. Moreover, we are going to see in the next section that we can also get them, by applying the Operation H.

## Operation H

$$
\left\langle h, l \right\rangle
\rightarrow
\begin{cases}
    \left\langle l, h - l \right\rangle, \text{if } l > h - l\\
    \left\langle h - l, l \right\rangle, \text{if } l \leqslant h - l
\end{cases}
$$

### Conclusion

As we can see, we do not need the Operation L, just the Operation H.

Moreover, we can always assume that $l \leqslant \min(l, h - l)$ because, it that is not the case, we can apply an Operation L to get such pair (make $l = h - l$). It doesn't make any difference because we still get all the pairs we would get starting with the original pair. Thus:

$$
\left\langle h, l \right\rangle
\rightarrow
\left\langle h - l, l \right\rangle
$$

## Naive Algorithm

```plain
solve(h, l, x):
    if h == x or $l == x$, then YES;
    if x > \max(h, l), then NO;
    if h == 0 or l == 0, then NO;
    if h < l, then swap(h, l);
    l = min(l, h - l);
    h = h - l;
    return solve(h, l, x);
```

## Optimizing the Algorithm

The problem with the previous algorithm is that it may repeate the operation $h = h - l$ many times. We can skip most of them.

First, let's look for the number $\alpha \in \mathbb{Z}_+$ such that $x = h - \alpha \cdot l$ (if it exists). That number can be computed as:

$$ \alpha = \dfrac{h - x}{l} $$

If the number we are looking for exist, such calculation will be an integer number.

If we cannot get $x$ yet, then we want to skip as many operations as possible. In other words, what we want is to find the smallest number $\beta \in \mathbb{Z}_+$ such that $l > h - \beta \cdot b$, it is the number of times we have to perform the operation for the values of the pair to swap places. That $k$ can be computed as:

$$ \beta = \left\lceil \dfrac{h - l}{l} \right\rceil $$

What we are going to do is to perform both searches at the same time, with the drawback of maybe having to run the Operation H twice. We are going to compute:

$$ \gamma = \max\left(1, \left\lfloor \dfrac{h - \max(x, l)}{l} \right\rfloor \right)$$

Notice that:

1. it will perform at least one Operation H;
2. $\gamma \leqslant \alpha$ and $\gamma \leqslant \beta$;
   1. and it will give us the smallest of them (more or less);
3. with $\gamma$, we save some steps in the computation process, thus optimizing the algorithm;

## Optimized Algorithm

```plain
solve(h, l, x):
    if h == x or $l == x$, then YES;
    if x > \max(h, l), then NO;
    if h == 0 or l == 0, then NO;
    if h < l, then swap(h, l);
    l = min(l, h - l);
    h = max(1, (h - max(x, l)) / l);
    return solve(h, l, x);
```

## Catches

In this problem, the numbers are too big, and they may not fit into a double precision number (I got an error for converting a number to double, overflow). Therefore, all operations must stick to integral values.
*/

// ==================== Code ====================

#include <algorithm>
#include <cmath>
#include <iostream>

using Number = long long int;

bool solve(Number high, Number low, Number target) {
    if (high == target || low == target) {
        return true;
    }
    if (high < low) {
        std::swap(high, low);
    }
    low = std::min(low, high - low);
    if (target > std::max(high, low) || high == 0 || low == 0) {
        return false;
    }
    Number k = std::max(Number(1), (high - std::max(target, low)) / low);
    return solve(high - low * k, low, target);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        Number a, b, x;
        std::cin >> a >> b >> x;
        if (solve(a, b, x)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
