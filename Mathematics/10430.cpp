// https://www.acmicpc.net/problem/10430
// Name: 나머지
// Topic: Mathematics

#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << '\n';
    cout << (A % C + B % C) % C << '\n';
    cout << (A * B) % C << '\n';
    cout << (A % C * B % C) % C;
}