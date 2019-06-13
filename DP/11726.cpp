// https://www.acmicpc.net/problem/11726
// Name: 2xn 타일링
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int make2Xn(vector<int> &v, int n) {
    if (v[n] != -1) return v[n];
    if (n > 2) v[n] = (make2Xn(v, n-1) + make2Xn(v, n-2)) % 10007;
    return v[n];
}

int top_down() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 1, v[2] = 2;
    cout << make2Xn(v, num);
}

int bottom_up() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 1, v[2] = 2;
    for (int i = 3; i <= num; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }
    cout << v[num];
}