// https://www.acmicpc.net/problem/12813
// Name: 이진수 연산
// Topic: stl container(bitset)

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<100000> b1, b2;
    cin >> b1 >> b2;
    cout << (b1 & b2) << '\n';
    cout << (b1 | b2) << '\n';
    cout << (b1 ^ b2) << '\n';
    cout << ~(b1) << '\n';
    cout << ~(b2) << '\n';
    return 0;
}