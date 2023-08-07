import sys

MAX = float('inf')
max_value = 501


def dijkstra(origem, destino):
    custo = [MAX] * max_value
    passou = [0] * max_value

    custo[origem] = 0
    atual = origem

    while atual != destino:
        for i in range(1, vertices + 1):
            if custo[i] > custo[atual] + g[atual][i]:
                custo[i] = custo[atual] + g[atual][i]

        minimo = MAX
        passou[atual] = 1

        for i in range(1, vertices + 1):
            if custo[i] < minimo and not passou[i]:
                minimo = custo[i]
                atual = i

        # Caso não seja possível ir a lugar algum saindo da origem
        if minimo == MAX:
            return MAX

    return custo[destino]


while True:
    vertices, arestas = map(int, input().split())

    if vertices == 0 and arestas == 0:
        break

    g = [[MAX] * max_value for _ in range(max_value)]

    for i in range(1, vertices + 1):
        g[i][i] = 0

    for _ in range(arestas):
        origem, destino, peso = map(int, input().split())
        g[origem][destino] = peso
        if g[destino][origem] != MAX:
            g[origem][destino] = 0
            g[destino][origem] = 0

    consultas = int(input())

    for _ in range(consultas):
        origem, destino = map(int, input().split())

        shortest_path = dijkstra(origem, destino)

        if shortest_path == MAX:
            print("Nao e possivel entregar a carta")
        else:
            print(shortest_path)

    print()