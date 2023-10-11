# [SPOJ NAJPF - Pattern Find](https://www.spoj.com/problems/NAJPF/)

Finding a string is not complicated since there are methods in C to handle that (`strstr`). The difficult part is to make the search efficiently. To do so, one can find the first ocurrence of the substring and then shift the original string to the end of the first ocurrence. In that way, it doesn't have to go through the beginning of the string every time.
