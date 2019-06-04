// https://www.acmicpc.net/problem/11720
// Name: 숫자의 합

#include <cstdio>

int main() {
    int num, temp;
    int sum = 0;

    scanf("%d", &num);
    while(num--) {
        scanf("%1d", &temp);
        sum += temp;
    }

    printf("%d", sum);
    return 0;
}

