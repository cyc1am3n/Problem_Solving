# https://www.acmicpc.net/problem/9095
# Name: 1,2,3 더하기
# Topic: Dynamic Programming

def solution(N):
    dic = {}
    for i in range(1, N + 1):
        if i == 1:
            dic[i] = 1
        else:
            if i == 2:
                dic[i] = dic[i - 1] + 1
            elif i == 3:
                dic[i] = dic[i - 1] + dic[i - 2] + 1
            else:
                dic[i] = dic[i - 1] + dic[i - 2] + dic[i - 3]
    return dic[N]

if __name__ == '__main__':
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))
    for j in range(n):
        print(solution(a[j]))
