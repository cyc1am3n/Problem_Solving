// https://www.acmicpc.net/problem/1676
// Name: 팩토리얼 0의 개
// Topic: Mathematics

#include <iostream>
using namespace std;

int main() {
    int num, zero = 0;
    cin >> num;
    for(int i = 5; i <= num; i++) {
        int temp = i;
        while(temp % 5 == 0) {
            zero++;
            temp /= 5;
        }
    }
    cout << zero;
}