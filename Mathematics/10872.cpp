// https://www.acmicpc.net/problem/10872
// Name: 팩토리얼
// Topic: Mathematics

#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int fac = 1;
    for(int i = 2; i <= num; i++) fac *= i;
    cout << fac;
}