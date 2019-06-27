// https://www.acmicpc.net/problem/2004
// Name: 조합 0의 개수
// Topic: Mathematics

#include <iostream>
#include <algorithm>
using namespace std;

long long findNum(long long n, int find) {
    long long count = 0;
    for (long long i = find; n / i >= 1; i *= find)
        count += n / i;
    return count;
}

int main() {
    long long n, m, five, two;
    cin >> n >> m;
    five = findNum(n, 5) - findNum(n - m, 5) - findNum(m, 5);
    two = findNum(n, 2) - findNum(n - m, 2) - findNum(m, 2);
    cout << min(five, two);
}