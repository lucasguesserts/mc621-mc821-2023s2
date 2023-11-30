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
# [Kattis - Estimating the Area of a Circle](https://open.kattis.com/problems/estimatingtheareaofacircle)

In this problem, given a radius $r$, a number of tested points $n$ and the
number $m$ of points that are inside the circle, we are to output both

* The actual area of the circle of radius $r$, which is $\pi r^2$;

* The area that would be estimated (without using $\pi$) by scaling the area of the circumscribed
square (which is $4r^2$) by the proportion of points that were verified to be
inside the circle (which is $p = m/n$). Thus the expression for the estimated
area is $4r^2 p$.*/

// ==================== Code ====================

#include <iostream>

#define PI 3.14159265358979323846

using namespace std;

int main() {
    double r;
    unsigned in, total;
    while ((cin >> r >> total >> in) && total)
        cout << (PI * r * r) << " " << (4 * r * r) * ((1.0 * in) / total) << endl;
    return 0;
}
