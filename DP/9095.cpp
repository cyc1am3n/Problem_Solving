// https://www.acmicpc.net/problem/9095
// Name: 1, 2, 3 더하기
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int add_123(vector<int> &v, int n) {
    if (v[n] != -1) return v[n];
    v[n] = add_123(v, n-3) + add_123(v, n-2) + add_123(v, n-1);
    return v[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(12, -1);
    v[1] = 1, v[2] = 2, v[3] = 4;
    while(n--) {
        int num;
        cin >> num;
        cout << add_123(v, num) << '\n';
    }
}