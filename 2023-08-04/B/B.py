import sys

def altura(i, alturas, pais):
    if alturas[i] is None:
        alturas[i] = 1 + altura(pais[i], alturas, pais)
    return alturas[i]

def monta_arvore(n: int):
    valores = list(map(int, input().split()))
    pais = [-1] + list(map(lambda s: int(s)-1, input().split()))
    alturas = [ None ]*n
    alturas[0] = 0
    for i in range(n):
        alturas[i] = altura(i, alturas, pais)
    return pais, valores, alturas, max(alturas)

def processa_queries(n, q, pais, valores, alturas, altura_maxima):
    tabela = [ dict() ]*(altura_maxima + 1)
    tabela[0][(0,0)] = valores[0]**2

    def f(x,y):
        h = alturas[x] # garantido que é = alturas[y]
        if (x, y) not in tabela[h]:
            tabela[h][x,y] = valores[x]*valores[y] + f(pais[x], pais[y])
        return tabela[h][x,y]

    for _ in range(q):
        x, y = map(int, input().split())
        print(f(x-1,y-1))

def main():
    sys.setrecursionlimit(int(1e5))
    n, q = map(int, input().split())
    pais, valores, alturas, altura_maxima = monta_arvore(n)
    processa_queries(n, q, pais, valores, alturas, altura_maxima)

main()
