INPUT_FILE = 'in.txt'
OUTPUT_FILE = 'out.txt'

def cases_from_file(filename):
    file = open(filename, "r")
    ncases = int(file.readline())
    cases = []
    for _ in range(ncases):
        cases.append(int(file.readline()))
    file.close()
    return cases

def answers_from_file(filename):
    file = open(filename, "r")
    answers = []
    for line in file:
        a, b = map(int, line.split())
        answers.append((a,b))
    file.close()
    return answers

def sum_of_digits(n):
    s = 0
    while n:
        s += n%10
        n //= 10
    return s

if __name__ == '__main__':
    cases = cases_from_file(INPUT_FILE)
    answers = answers_from_file(OUTPUT_FILE)
    fail = False
    if len(cases) != len(answers):
        print(f'WRONG ANSWER: expected {len(cases)} answers, got {len(answers)}.')
        exit(1)
    for i in range(len(cases)):
        n = cases[i]
        a, b = answers[i]
        print(f'case #{i+1}: n = {n}, answer = {a}+{b}.', end='\n\t')
        if a + b != n:
            print(f'WRONG ANSWER. {a}+{b} = {a+b}')
            fail = True
        else:
            A = sum_of_digits(a)
            B = sum_of_digits(b)
            if abs(A-B) > 1:
                print(f'WRONG ANSWER. len({a}) = {A}, len({b}) = {B}')
                fail = True
            else:
                print('OK')
    print('\n' + '-'*30)
    if fail:
        print('FAIL')
    else:
        print('PASS')
