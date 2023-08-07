def find(parent, i):
    if parent[i] == i:
        return i
    return find(parent, parent[i])

def union(parent, rank, x, y):
    x_root = find(parent, x)
    y_root = find(parent, y)

    if rank[x_root] < rank[y_root]:
        parent[x_root] = y_root
    elif rank[x_root] > rank[y_root]:
        parent[y_root] = x_root
    else:
        parent[y_root] = x_root
        rank[x_root] += 1

def kruskal(graph, m):
    graph = sorted(graph, key=lambda x: x[2])
    parent = []
    rank = []
    cost = 0

    for i in range(m):
        parent.append(i)
        rank.append(0)

    for edge in graph:
        x, y, weight = edge
        x_root = find(parent, x)
        y_root = find(parent, y)

        if x_root != y_root:
            cost += weight
            union(parent, rank, x_root, y_root)

    return cost

def main():
    while True:
        m, n = map(int, input().split())
        if m == 0 and n == 0:
            break

        graph = []
        total_cost = 0

        for _ in range(n):
            x, y, z = map(int, input().split())
            graph.append((x, y, z))
            total_cost += z

        min_cost = kruskal(graph, m)
        max_savings = total_cost - min_cost
        print(max_savings)

if __name__ == '__main__':
    main()
