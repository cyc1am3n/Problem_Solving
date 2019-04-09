# https://www.acmicpc.net/problem/2579
# Name: 계단 오르기
# Topic: Dynamic Programming


def solution(stair):
    N = len(stair)
    dic = {1: stair[0], 2: stair[0]+stair[1]}
    for i in range(3, N + 1):
        if i == 3:
            dic[i] = max(stair[1]+stair[2], stair[0]+stair[2])
        else:
            dic[i] = max(dic[i - 3] + stair[i - 2] + stair[i - 1], dic[i - 2] + stair[i - 1])
    return dic[N]

if __name__ == '__main__':
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))

    print(solution(a))
