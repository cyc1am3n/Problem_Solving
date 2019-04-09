# https://www.acmicpc.net/problem/1463
# Name: 1로 만들기
# Topic: Dynamic Programming

def solution(N):
    dic = {}
    for i in range(1, N + 1):
        if i == 1:
            dic[i] = 0
        else:
            dic[i] = dic[i - 1] + 1
            if i % 3 == 0:
                dic[i] = min(dic[i/3] + 1, dic[i])
            elif i % 2 == 0:
                dic[i] = min(dic[i/2] + 1, dic[i])
    return dic[N]

if __name__ == '__main__':
    n = int(input())
    print(solution(n))