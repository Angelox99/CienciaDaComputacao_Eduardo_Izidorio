def dfs(v, graph, visited, stack):
    visited[v] = True
    stack[v] = True

    for neighbor in graph[v]:
        if not visited[neighbor]:
            if dfs(neighbor, graph, visited, stack):
                return True
        elif stack[neighbor]:
            return True

    stack[v] = False
    return False


def is_bolada(N, M, relations):
    graph = [[] for _ in range(N+1)]

    for relation in relations:
        U, V = relation
        graph[U].append(V)

    visited = [False] * (N+1)
    stack = [False] * (N+1)

    for i in range(1, N+1):
        if not visited[i]:
            if dfs(i, graph, visited, stack):
                return "Bolada"

    return "Não Bolada"


# Leitura da entrada
N, M = map(int, input().split())
relations = []
for _ in range(M):
    U, V = map(int, input().split())
    relations.append((U, V))

# Verificar se a cadeia é bolada
result = is_bolada(N, M, relations)

# Imprimir o resultado
print(result)
