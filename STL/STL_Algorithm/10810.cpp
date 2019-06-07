// https://www.acmicpc.net/problem/10810
// Name: 공 넣기
// Topic: stl algorithm

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);

    while(m--) {
        int i, j, k;
        cin >> i >> j >> k;
        auto it = v.begin() - 1;
        fill(it + i, it + j + 1, k);
    }

    for (auto x : v) {
        cout << x << ' ';
    }
}