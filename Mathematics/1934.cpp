// https://www.acmicpc.net/problem/1934
// Name: 최소공배수
// Topic: Mathematics

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(a < b) swap (a, b);
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }
}