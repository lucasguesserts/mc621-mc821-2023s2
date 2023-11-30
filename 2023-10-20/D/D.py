"""
==================== LICENSE ====================

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

 ==================== Solution Description ====================

# [Codeforces 1178/B - WOW Factor](https://codeforces.com/problemset/problem/1178/B)

keep three counts:

1. $n_{w}$: number of previous "w";
2. $n_{wo}$: number of previous "wo";
3. $n_{wow}$: number of previous "wow";

Now start from the beginning of the string:

1. if you find a $o$, then $n_{wo}$, the number of "wo", must be increased by $n_{w}$, the number of previous "w";
2. if you find a $w$ (i.e. both the current and the previous characters are a $v$), then the $n_{w}$, number of "w", must be increased by 1 and $n_{wow}$, the number of "wow", must be increased by the number of previous "wo";

The solution is $n_{wow}$ by the end of the algorithm. Complexity: $\mathcal{O}(n)$.
"""

# ==================== Code ====================

# adapted from https://codeforces.com/blog/entry/68534

if __name__ == "__main__":
    s = input()
    n_w = 0
    n_wo = 0
    n_wow = 0
    prev_char = ""
    currente_char = ""
    for currente_char in s:
        if currente_char == "o":
            n_wo += n_w
        elif currente_char == "v" and prev_char == "v":
            n_w += 1
            n_wow += n_wo
        prev_char = currente_char
    print(n_wow, end="")
