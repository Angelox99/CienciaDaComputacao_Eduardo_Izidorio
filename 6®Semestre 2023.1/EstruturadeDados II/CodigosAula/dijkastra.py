from collections import defaultdict

# criar o grafo


def criarGrafo(arestas):
    graph = defaultdict(dict)
    for u, v, dist in arestas:
        graph[u][v] = dist
    return graph


arestasEntrada = [['a', 'b', 6], ['a', 'c', 3], ['b', 'c', 1], ['c', 'b', 4], [
    'b', 'd', 2], ['c', 'd', 8], ['c', 'e', 2], ['d', 'e', 9], ['e', 'd', 7]]

G = criarGrafo(arestasEntrada)
print(G)


def dijkstra(graph, src):
    # The only criterium of adding a node to queue is if its distance has changed at the current step.
    queue = [src]
    minDistances = {v: float("inf") for v in graph}
    minDistances[src] = 0
    predecessor = {}

    while queue:
        currentNode = queue.pop(0)
        for neighbor in graph[currentNode]:
            # get potential newDist from start to neighbor
            newDist = minDistances[currentNode] + graph[currentNode][neighbor]

            # if the newDist is shorter to reach neighbor updated to newDist
            if newDist < minDistances[neighbor]:
                minDistances[neighbor] = min(newDist, minDistances[neighbor])
                queue.append(neighbor)
                predecessor[neighbor] = currentNode

    return minDistances, predecessor


shortest_path_cost, predecessor = dijkstra(G, 'a')
print("Menor caminho de 'a' para todos os outros nós:", shortest_path_cost)
print("Predecessor dictionary:", predecessor)

# Unifrom Cost Search - shortest path between Source and Destination (Greedy)
def UCS(graph, src, dest):
    minDistances, predecessor = dijkstra(graph, src)

    path = []
    currentNode = dest
    while currentNode != src:
        if currentNode not in predecessor:
            print("Não há caminho!")
            break
        else:
            path.insert(0, currentNode)
            currentNode = predecessor[currentNode]
    path.insert(0, src)

    if dest in minDistances and minDistances[dest] != float("inf"):
        print('Menor distância é ' + str(minDistances[dest]))
        print('E o caminho é ' + str(path))


UCS(G, 'a', 'd')
