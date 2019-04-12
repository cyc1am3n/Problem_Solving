# https://www.acmicpc.net/problem/10817
# Name: 세 수

if __name__ == '__main__':
    N = input().split(' ')
    N = [int(i) for i in N]
    N.sort()
    print(N[1])
