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
# [202 - Repeating Decimals](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5140)

The idea is to iteratively compute the remainder and the quotient of the division (literally, follow the division algorithm). When the remainder repeats, there the cycle begins. If, at some point, the remainder is zero, then it does not repeat.

To efficiently compute that, store the remainders seen so far in a map (key is the remainder, value is the index where it has last been seen). Also store all the quotients and mark where the decimal point is.
*/

// ==================== Code ====================

// https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20202%20-%20Repeating%20Decimals/src/UVa%20202%20-%20Repeating%20Decimals.cpp

#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
    int a, b;
    int result, remainder, index;
    map<int, int> remainderIndex;
    vector<int> decimalDigits;

    while (scanf("%d %d", &a, &b) != EOF) {
        remainderIndex.clear();
        decimalDigits.clear();
        index = 0;

        result = a / b;
        remainder = a % b;
        while (!remainderIndex.count(remainder)) {
            remainderIndex[remainder] = index++;
            result = remainder * 10 / b;
            decimalDigits.push_back(result);
            remainder = (remainder * 10) % b;
        }

        int cycleStartIndex = remainderIndex[remainder];
        int nCurDigit = 0;

        printf("%d/%d = %d.", a, b, a / b);
        for (; nCurDigit < cycleStartIndex && nCurDigit < 50; nCurDigit++) {
            printf("%d", decimalDigits[nCurDigit]);
        }
        printf("(");
        for (; nCurDigit < index && nCurDigit < 50; nCurDigit++) {
            printf("%d", decimalDigits[nCurDigit]);
        }

        if (nCurDigit >= cycleStartIndex) {
            if (nCurDigit < index)
                printf("...");
            printf(")\n");
        }
        printf("   %d = number of digits in repeating cycle\n\n",
            index - cycleStartIndex);
    }

    return 0;
}
