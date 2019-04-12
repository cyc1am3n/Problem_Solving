# https://www.acmicpc.net/problem/10844
# Name: 쉬운 계단 수
# Topic: Dynamic Programming

def solution(n):
    dp = {1:[0, 1, 1, 1, 1, 1, 1, 1, 1, 1]}
    for i in range(2, n + 1):
        dp[i] = [0 for _ in range(10)]
        for j in range(10):
            if j == 0:
                dp[i][j] = dp[i - 1][1]
            elif 1 <= j <= 8:
                dp[i][j] = dp[i - 1][j - 1] + dp[i -1][j + 1]
            else:
                dp[i][j] = dp[i - 1][8]
    return sum(dp[n]) % 1000000000

if __name__ == '__main__':
    n = int(input())
    print(solution(n))