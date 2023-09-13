class Country:
    def __init__ (self, index, name, winning_probabilities):
        self.index = index
        self.name = name
        self.winning_probability = list(map(lambda x: x / 100.0, winning_probabilities))
        return

    def pwins(self, other):
        return self.winning_probability[other.index]

    def __str__(self):
        return f"{self.name} {self.winning_probability}"

class Classification:
    def __init__ (self, country: Country, probability: float):
        self.country = country
        self.probability = probability
        return

class Championship:
    def __init__ (self, countries):
        self.classifications = [
            [Classification(country, 1.0)]
            for country in countries
        ]
        while (len(self.classifications) > 1):
            self._reduce()

    def _reduce (self):
        new_classifications = []
        for i in range(0, len(self.classifications), 2):
            lhs = self.classifications[i]
            rhs = self.classifications[i + 1]
            new_classifications.append(self._make_classifications(lhs, rhs))
        self.classifications = new_classifications
        return

    def _make_classifications(self, lhs: list[Classification], rhs: list[Classification]):
        c = []
        for home in lhs:
            c.append(Classification(
                home.country,
                sum([home.probability * away.probability * home.country.pwins(away.country) for away in rhs])
            ))
        for home in rhs:
            c.append(Classification(
                home.country,
                sum([home.probability * away.probability * home.country.pwins(away.country) for away in lhs])
            ))
        return c

if __name__ == "__main__":
    country_name_list = [input() for _ in range(16)]
    winning_probability_matrix = [list(map(float, input().split())) for _ in range(16)]
    countries = [Country(i, country_name_list[i], winning_probability_matrix[i]) for i in range(16)]
    championship = Championship(countries)
    for classification in championship.classifications[0]:
        print("{:10} p={:.2f}%".format(classification.country.name, 100*classification.probability))
