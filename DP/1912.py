# https://www.acmicpc.net/problem/1912
# Name: 연속합
# Topic: Dynamic Programming


def solution(N):
    length = len(N)
    dp = {0: N[0]}
    ans = N[0]
    for i in range(1, length):
        if dp[i - 1] + N[i] > N[i]:
            dp[i] = dp[i - 1] + N[i]
        else:
            dp[i] = N[i]

        if ans < dp[i]:
            ans = dp[i]
    print(ans)

if __name__ == '__main__':
    n = input()
    a = input()
    a = [int(i) for i in a.split(' ')]
    solution(a)
