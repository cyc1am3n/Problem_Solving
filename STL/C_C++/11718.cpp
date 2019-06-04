// https://www.acmicpc.net/problem/11718
// Name: 그대로 출력하기

#include <cstdio>

int main() {
    char c[100];
    while(scanf("%[^\n]\n", c) == 1) {
        printf("%s\n", c);
    }
    return 0;
}

