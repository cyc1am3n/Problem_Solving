from collections import deque

graph_list = {'A': set(['B', 'C']),
              'B': set(['A', 'D', 'E']),
              'C': set(['A', 'F']),
              'D': set(['B']),
              'E': set(['B', 'F']),
              'F': set(['C', 'E'])}

def BFS_with_adj_list(graph, start):
    visited = []
    queue = deque([start])

    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            queue += graph[n] - set(visited)
    return visited

def BFS_paths_with_adj_list(graph, start, end):
    queue = deque([(start, [start])])
    result = []

    while queue:
        n, path = queue.popleft()
        if n == end:
            result.append(path)
        else:
            for m in graph[n] - set(path):
                queue.append((m, path + [m]))
    return result

if __name__ == '__main__':
    print(graph_list)
    print(BFS_with_adj_list(graph_list, 'A'))
    print(BFS_paths_with_adj_list(graph_list, 'C', 'F'))
