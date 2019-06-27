// https://www.acmicpc.net/problem/2609
// Name: 최대공약수와 최소공배수
// Topic: Mathematics

#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int a = A, b = B;
    if (a < b) swap(a, b);
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << a << '\n';
    cout << A * B / a;
}