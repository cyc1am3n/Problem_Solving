# https://www.acmicpc.net/problem/1003
# Name: 피보나치 함수
# Topic: Dynamic Programming


def solution(N):
    dic = {0: [1, 0], 1:[0, 1]}

    for i in range(2, N + 1):
        dic[i] = [dic[i - 1][0] + dic[i - 2][0], dic[i - 1][1] + dic[i - 2][1]]
    return str(dic[N][0])+" "+str(dic[N][1])

if __name__ == '__main__':
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))

    for j in range(n):
        print(solution(a[j]))
