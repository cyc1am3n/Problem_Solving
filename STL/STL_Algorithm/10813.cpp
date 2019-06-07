// https://www.acmicpc.net/problem/10813
// Name: 공 바꾸기
// Topic: stl algorithm

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 1; i <= n ; i++) v.push_back(i);

    while(m--) {
        int a, b;
        cin >> a >> b;
        swap(v[a - 1], v[b - 1]);
    }

    for (auto x : v) cout << x << ' ';
}