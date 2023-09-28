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
check manually for the above five cases.