# BFS - Algoritmo de Busca em Largura
from collections import defaultdict


class Graph:
    def __init__(self):
        #  Quando você cria um defaultdict, fornece uma função usada para criar valores, nesse caso criou-se a lista
        self.graph = defaultdict(list)

    # função que adiciona os vértices ao grafo
    def addEdge(self, u, v):
        self.graph[u].append(v)
        # self.graph[v].append(u) # caso fosse bidirecionado

    # Função parea imprimir o BFS do Grafo, recebe o primeiro nó visitado
    def BFS(self, s):
        # marca todos os vértices como não visitados
        visited = [False] * (len(self.graph))

        positive_infinity = float('inf')
        distance = [positive_infinity] * (len(self.graph))

        # visited = [False, False,False,False,False,False]

        # Cria uma fila vazia para o BFS
        queue = []

        # pega o nó de origem, marca como visitado e insere na fila
        visited[s] = True
        distance[s] = 0
        queue.append(s)

        # enquanto a fila não for vazia
        while queue:

            # retira o primeiro elemento da fila
            s = queue.pop(0)
            print(s, " - ",  distance[s])  # aqui é a execução do BFS

            for v in self.graph[s]:
                # print(visited[v], v)
                if visited[v] == False:
                    queue.append(v)
                    visited[v] = True
                    distance[v] = distance[s] + 1


# MAIN
g = Graph()
g.addEdge(0, 2)
g.addEdge(0, 4)
g.addEdge(0, 3)
g.addEdge(2, 4)
g.addEdge(3, 4)
g.addEdge(3, 5)
g.addEdge(4, 5)
g.addEdge(5, 1)
g.addEdge(1, 2)
g.addEdge(1, 4)

inicio = 0
g.BFS(inicio)
