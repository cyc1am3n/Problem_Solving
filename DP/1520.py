# https://www.acmicpc.net/problem/1520
# Name: 내리막 길
# Topic: Dynamic Programming & DFS

n, m = -1, -1
arr = []
dp = []
pos = [[1, 0], [-1, 0], [0, 1], [0, -1]]

def search(row, col):
    if dp[row][col] != -1:
        return dp[row][col]
    if row == 0 and col == 0:
        return 1

    dp[row][col] = 0
    for _, (x, y) in enumerate(pos):
        x, y = x + row, y + col
        if 0 <= x < n and 0 <= y < m:
            if arr[x][y] > arr[row][col]:
                dp[row][col] = dp[row][col] + search(x, y)

    return dp[row][col]

if __name__ == '__main__':
    n, m = input().split(' ')
    n, m = int(n), int(m)
    for i in range(n):
        a = input()
        arr.append([int(j) for j in a.split(' ')])
        dp.append([-1 for _ in range(m)])
    print(search(n - 1, m - 1))

