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
# [Kattis - Sanic](https://open.kattis.com/problems/sanic)

Sanic is a small unitary circle rolling against the inner wall of a big circle of radius $r \geq 1.1$.

When rolling, Sanic's center has a trajectory which is a circle concentric to the big circle and whose radius is $r-1$.
Since Sanic has no drag, his center travels as much as any fixed point of his circumference.

![Image showing a small (unitary) circle inside of big circle of radius r. When the small circle rolls inside the bigger one, its center describes a circle of radius r-1 concentric to the big circle.](./sanic.svg)

When Sanic completes the lap, his center will have travelled a distance of

$$ \Delta s = 2\pi(r-1) .$$

But each time Sanic's center travels $2\pi$ units, he will have completed one rotation, since by then
any fixed point in his circumference will have travelled around the whole circumference.

Hence, the amount of rotations he will perform is exactly

$$r-1.$$*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

int main() {
    double r;
    cin >> r;
    cout << (r - 1.0) << endl;
    return 0;
}
