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
# [Archer](https://codeforces.com/problemset/problem/312/B)

Let:

* `a/b`: be the probability that **SmallR** shoots the target;
* `c/d`: be the probability that **Zanoes** shoots the target;
* `p`: the probability that **SmallR** wins;

Since SmallR starts, its probability `p` of winning is:

> p = (SmallR shoots the target) OR (SmallR misses the target AND Zanoes misses the target AND SmallR shoots the target) OR (SmallR misses the target two times AND Zanoes misses the target two times AND SmallR shoots the target) OR ...

Which can be converted in the following calculation:

```plain
p = a/b + (1-a/b)*(1-c/d)*a/b + (1-a/b)^2*(1-c/d)^2*a/b + ...
  = (a/b) * sum_{i = 0 ... +oo}[(1-a/b)^i * (1-c/d)^i]
```

That is the infinite sum of a Geometric Progression with first term equals to `a/b` and ratio equals to `(1-a/b)*(1-c/d)`. Thus:

```plain
a1 = a/b
q = (1-a/b)*(1-c/d)
p = a1 / (1 - q)
```

*/

// ==================== Code ====================

#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

int main() {
    auto a = double{0};
    auto b = double{0};
    auto c = double{0};
    auto d = double{0};
    cin >> a >> b >> c >> d;
    const auto a1 = a / b;
    const auto q = (1 - a / b) * (1 - c / d);
    const auto p = a1 / (1 - q);
    cout << std::setprecision(12) << fixed << p;
    return 0;
}
