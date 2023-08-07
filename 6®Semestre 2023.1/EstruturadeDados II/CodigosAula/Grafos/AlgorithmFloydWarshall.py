# import sys

# class Grafo:
#     def __init__(self, v):
#         self.v = v
#         self.rota = [[float('inf') for _ in range(v)] for _ in range(v)]

#     def floyd_warshall(self):
#         dist = [[float('inf') for _ in range(self.v)] for _ in range(self.v)]

#         for i in range(self.v):
#             for j in range(self.v):
#                 dist[i][j] = self.rota[i][j]

#         for k in range(self.v):
#             for i in range(self.v):
#                 for j in range(self.v):
#                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

#         return dist

#     def find_shortest_path(self, origem, destino):
#         dist = self.floyd_warshall()

#         if dist[origem][destino] < float('inf'):
#             sys.stdout.write(str(dist[origem][destino]) + '\n')
#         else:
#             sys.stdout.write("Nao e possivel entregar a carta\n")
#         sys.stdout.flush()

# def main():
#     while True:
#         n, e = map(int, sys.stdin.readline().split())
#         if n == 0 and e == 0:
#             break

#         grafo = Grafo(n+1)

#         for i in range(e):
#             x, y, z = map(int, sys.stdin.readline().split())
#             if grafo.rota[y][x] != float('inf'):
#                 grafo.rota[x][y] = 0
#                 grafo.rota[y][x] = 0
#             else:
#                 grafo.rota[x][y] = z

#         k = int(sys.stdin.readline())
#         for i in range(k):
#             o, d = map(int, sys.stdin.readline().split())
#             grafo.find_shortest_path(o, d)
#         print()

# if __name__ == '__main__':
#     main()

import sys

class Grafo:
    def __init__(self, v):
        self.v = v
        self.rota = [[float('inf')] * v for _ in range(v)]

    def floyd_warshall(self):
        dist = [row[:] for row in self.rota]

        for k in range(self.v):
            for i in range(self.v):
                for j in range(self.v):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        return dist

    def find_shortest_path(self, origem, destino):
        dist = self.floyd_warshall()

        if dist[origem][destino] < float('inf'):
            sys.stdout.write(str(dist[origem][destino]) + '\n')
        else:
            sys.stdout.write("Nao e possivel entregar a carta\n")

def main():
    while True:
        n, e = map(int, input().split())
        if n == 0 and e == 0:
            break

        grafo = Grafo(n+1)

        for _ in range(e):
            x, y, z = map(int, input().split())
            if grafo.rota[y][x] != float('inf'):
                grafo.rota[x][y] = 0
                grafo.rota[y][x] = 0
            else:
                grafo.rota[x][y] = z

        k = int(input())
        for _ in range(k):
            o, d = map(int, input().split())
            grafo.find_shortest_path(o, d)
        print()

if __name__ == '__main__':
    main()
