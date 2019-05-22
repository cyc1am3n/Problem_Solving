# https://www.acmicpc.net/problem/11399
# Name: ATM
# Topic: Greedy Algorithm

def solution(n, time):
    time.sort()
    wait = 0

    for i in range(n):
        time[i] = time[i] + wait
        wait = time[i]

    return sum(time)

if __name__ == '__main__':
    n = int(input())
    time = [int(i) for i in input().split(' ')]
    print(solution(n, time))