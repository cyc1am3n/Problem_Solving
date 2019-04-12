graph_list = {'A': set(['B', 'C']),
              'B': set(['A', 'D', 'E']),
              'C': set(['A', 'F']),
              'D': set(['B']),
              'E': set(['B', 'F']),
              'F': set(['C', 'E'])}

def DFS_with_adj_list(graph, start):
    visited = []
    stack = [start]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            stack += graph[n] - set(visited)
    return visited

def DFS_paths_with_adj_list(graph, start, end):
    stack = [(start, [start])]
    result = []

    while stack:
        n, path = stack.pop()
        if n == end:
            result.append(path)
        else:
            for m in graph[n] - set(path):
                stack.append((m, path + [m]))
    return result

if __name__ == '__main__':
    print(graph_list)
    print(DFS_with_adj_list(graph_list, 'A'))
    print(DFS_paths_with_adj_list(graph_list, 'A', 'F'))