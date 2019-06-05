// https://www.acmicpc.net/problem/10824
// Name: 네 수
// Topic: string

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int num1 = stoll(a + b);
    long long int num2 = stoll(c + d);

    cout << num1 + num2;
}