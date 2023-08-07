import sys

class Grafo:
    def __init__(self, v):
        self.v = v
        self.rota = [[float('inf') for _ in range(v)] for _ in range(v)]

    def dijkstra(self, origem, destino):
        fr = [-1] * self.v
        parnt = [-1] * self.v
        cst = [float('inf')] * self.v

        fr[origem] = origem
        cst[origem] = 0

        while True:
            mincst = float('inf')
            
            for w in range(self.v):
                if parnt[w] == -1 and mincst > cst[w]:
                    mincst = cst[w]
                    w0 = w
            if mincst == float('inf'):
                break
            parnt[w0] = fr[w0]
            for w in range(self.v):
                if cst[w] > cst[w0] + self.rota[w0][w]:
                    cst[w] = cst[w0] + self.rota[w0][w]
                    fr[w] = w0

        if cst[destino] < float('inf'):
            sys.stdout.write(str(cst[destino]) + '\n')
        else:
            sys.stdout.write("Nao e possivel entregar a carta\n")
        sys.stdout.flush()

def main():
    while True:
        n, e = map(int, sys.stdin.readline().split())
        if n == 0 and e == 0:
            break

        grafo = Grafo(n+1)

        for i in range(e):
            x, y, z = map(int, sys.stdin.readline().split())
            if grafo.rota[y][x] != float('inf'):
                grafo.rota[x][y] = 0
                grafo.rota[y][x] = 0
            else:
                grafo.rota[x][y] = z

        k = int(sys.stdin.readline())
        for i in range(k):
            o, d = map(int, sys.stdin.readline().split())
            grafo.dijkstra(o, d)
        print()
if __name__ == '__main__':
    main()