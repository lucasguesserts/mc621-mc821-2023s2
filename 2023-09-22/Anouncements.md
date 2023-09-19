# Anouncements - Contest 2023-09-22

## B

Be careful with the input of the Euclid Problem.

In C++, I recommend you to use:

```c++
#include <iostream>

using namespace std;

int main() {
  while (true) {
    long long int a, b;
    cin >> a;
    if (cin.eof())
      break;
    cin >> b;
    // YOUR SOLUTION HERE
  }
  return 0;
}
```

## F

It accepts the Python programming language, but only the version 2.7 of it (no version 3 is supported).

For those who wants to use Python, add the following in your code:

```python
import sys

if sys.version_info[0] < 3:
    input_func = raw_input
else:
    input_func = input
```

and then use the method `input_func` instead of `input`. That should be enough kinda enough...
