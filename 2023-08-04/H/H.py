if __name__ == "__main__":
    number_of_cases = int(input())
    for _ in range(number_of_cases):
        number_of_tracks = int(input())
        cars_in_tracks = [int(x) for x in input().split()]
        total_number_of_cars = sum(cars_in_tracks)
        remainder = total_number_of_cars % number_of_tracks
        inconvenience = (number_of_tracks - remainder) * remainder
        print(inconvenience)
