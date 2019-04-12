# 알고리즘 문제풀이 전략 Chapter 16-02: 생화학 폭탄
# Topic: Back Tracking & BFS

position = [[-1, 0], [1, 0], [0, -1], [0, 1]]

def solution(city, size, start):
    time = 1
    this_step = [start]
    next_step = []
    visited = []

    while this_step: # loop if this_step isn't empty
        point = this_step.pop()
        visited.append(point)
        for (x, y) in position: # 4-way search
            next_point = [point[0] + x, point[1] + y]
            if 0 <= next_point[0] < size[1] and 0 <= next_point[1] < size[0] and next_point not in visited:
                if city[next_point[0]][next_point[1]] == 1:
                    next_step.append(next_point)
        if not this_step and next_step:
            this_step = list(next_step)
            next_step = []
            time = time + 1

    return time

if __name__ == '__main__':
    city = []
    size = [int(i) for i in input().split(' ')]
    for _ in range(size[1]):
        city_info = [int(i) for i in input().split(' ')]
        city.append(city_info)
    start = [int(i) - 1 for i in input().split(' ')]
    print(solution(city, size, start))

"""
Ex 1)
Input:
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
2 5

Output:
8

Ex 2)
Input:
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2

Output:
21
"""