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

# [542 - France '98](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=483)

The idea is to create a tree structure for the championship. In each node, one will store a list of countries, each one of them with its probability to reach that stage.

The way one combines two nodes is by considering the match between all countries of one node against all countries of the other node. Given:

* country `A` with probability `p_A`of being in that stage;
* country `B` with probability `p_B`of being in that stage;
* `p_AB` the probability that `A` wins against `B`;

then the probability that `A` is in the next stage is `sum_{B in the other node} p_A * p_B * p_AB`. In that way one can compute, for each country in the two nodes, the probability of being in the next stage.


```plain
[(Argentina, 0.87), (Brazil, 0.95)]--|
                                     |--[(Argentina, 0.64), (Brazil, 0.82), (Chile, 0.49), (Denmark, 0.12)]
[(Chile, 0.76), (Denmark, 0.25)]-----|
```

For storing and processing all that information, one can use a list of lists and, at each step, combine two adjacent lists. In the end, there will be one list containing all the countries.

The last thing required is to initialize the data. One can accomplish that by creating a list in which each element is a list containing a single country with probability `1.0`.
"""

# ==================== Code ====================


class Country:
    def __init__(self, index, name, winning_probabilities):
        self.index = index
        self.name = name
        self.winning_probability = list(map(lambda x: x / 100.0, winning_probabilities))
        return

    def pwins(self, other):
        return self.winning_probability[other.index]

    def __str__(self):
        return f"{self.name} {self.winning_probability}"


class Classification:
    def __init__(self, country: Country, probability: float):
        self.country = country
        self.probability = probability
        return


class Championship:
    def __init__(self, countries):
        self.classifications = [[Classification(country, 1.0)] for country in countries]
        while len(self.classifications) > 1:
            self._reduce()

    def _reduce(self):
        new_classifications = []
        for i in range(0, len(self.classifications), 2):
            lhs = self.classifications[i]
            rhs = self.classifications[i + 1]
            new_classifications.append(self._make_classifications(lhs, rhs))
        self.classifications = new_classifications
        return

    def _make_classifications(
        self, lhs: list[Classification], rhs: list[Classification]
    ):
        c = []
        for home in lhs:
            c.append(
                Classification(
                    home.country,
                    sum(
                        [
                            home.probability
                            * away.probability
                            * home.country.pwins(away.country)
                            for away in rhs
                        ]
                    ),
                )
            )
        for home in rhs:
            c.append(
                Classification(
                    home.country,
                    sum(
                        [
                            home.probability
                            * away.probability
                            * home.country.pwins(away.country)
                            for away in lhs
                        ]
                    ),
                )
            )
        return c


if __name__ == "__main__":
    country_name_list = [input() for _ in range(16)]
    winning_probability_matrix = [list(map(float, input().split())) for _ in range(16)]
    countries = [
        Country(i, country_name_list[i], winning_probability_matrix[i])
        for i in range(16)
    ]
    championship = Championship(countries)
    for classification in championship.classifications[0]:
        print(
            "{:10} p={:.2f}%".format(
                classification.country.name, 100 * classification.probability
            )
        )
