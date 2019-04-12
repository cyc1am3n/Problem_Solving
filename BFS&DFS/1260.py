# https://www.acmicpc.net/problem/1260
# Name: DFS와 BFS
# Topic: BFS & DFS

def DFS(graph, start):
    visited = []
    stack = [start]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack += temp
    return " ".join(str(i) for i in visited)

def BFS(graph, start):
    visited = []
    queue = [start]

    while queue:
        n = queue.pop(0)
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue += temp
    return " ".join(str(i) for i in visited)

if __name__ == '__main__':
    graph = {}
    n = input().split(' ')
    node, edge, start = [int(i) for i in n]
    for i in range(edge):
        edge_info = input().split(' ')
        n1, n2 = [int(j) for j in edge_info]
        if n1 not in graph:
            graph[n1] = [n2]
        elif n2 not in graph[n1]:
            graph[n1].append(n2)

        if n2 not in graph:
            graph[n2] = [n1]
        elif n1 not in graph[n2]:
            graph[n2].append(n1)

    print(DFS(graph, start))
    print(BFS(graph, start))