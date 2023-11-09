# [Kattis - Support Vector Machine](https://open.kattis.com/problems/svm)

There is no particular trick to this one; just implement the distance formula attentively:

$$ d(x) = \frac{(w^T x + b)}{\| w \|} $$

where $w$ is the given vector which is orthonormal to the hyperplane and $b$ is the offset from the origin.

We have to correctly implement:

* inner (dot) product $x^T y$ between vectors $x, y$ of same dimension;
* norm of a vector $y$ which is $\sqrt{y^T y}$;
* reading vectors for the hyperplane and queries;
* reading queries until `EOF` occurs. Here, we use `cin.ignore(1)` to dismiss newline symbols and `cin.peek()` to check whether the next character is `EOF`.