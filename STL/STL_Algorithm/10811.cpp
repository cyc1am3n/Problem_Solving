// https://www.acmicpc.net/problem/10811
// Name: 바구니 뒤집기
// Topic: stl algorithm

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) v[i] = i + 1;

    auto it = v.begin();
    while(m--) {
        int begin, end;
        cin >> begin >> end;
        reverse(it + begin - 1, it + end);
    }

    for (auto x : v) cout << x << ' ';
}