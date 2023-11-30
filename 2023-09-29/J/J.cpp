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
# [Amazing Function](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=5140)

The defined function $F$ is easy enough to implement. Its first 20 values
$F(0), F(1), F(2), \ldots, F(19)$ are respectively

```
5.59575411272515,
1.7320508075688774,
-0.26794919243112264,
-1.422649730810374,
-2.5773502691896253,
-1.4226497308103736,
-2.5773502691896244,
-1.4226497308103718,
-2.577350269189621,
-1.4226497308103645,
-2.577350269189606,
-1.4226497308103352,
-2.5773502691895476,
-1.4226497308102182,
-2.577350269189314,
-1.4226497308097508,
-2.5773502691883787,
-1.42264973080788,
-2.5773502691846373,
-1.4226497308003974
```

Although the values do not actually *repeat*, they do *converge* quickly into
two alternating values for odd and even parameters.

Since the problem asks us for the answer with 10 decimal digits, it is enough
to have the first 5 different values of the above sequence, which we may name as such:

```
F(0) = "5.5957541127",
F(1) = "1.7320508076",
F(2) = "-0.2679491924",
F(odd) = "-1.4226497308",
F(even) = "-2.5773502692"
```

We read the input as a string (since it can be thousands of digits long) and
check manually for the above five cases.*/

// ==================== Code ====================

#include <iostream>
#include <string>

#define RES_0 "5.5957541127"
#define RES_1 "1.7320508076"
#define RES_2 "-0.2679491924"
#define RES_ODD "-1.4226497308"
#define RES_EVEN "-2.5773502692"

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (s == "0") cout << RES_0;
        else if (s == "1") cout << RES_1;
        else if (s == "2") cout << RES_2;
        else {
            unsigned last = s[s.size() - 1] - '0';
            if (last % 2) cout << RES_ODD;
            else cout << RES_EVEN;
        }
        cout << endl;
    }
    return 0;
}
