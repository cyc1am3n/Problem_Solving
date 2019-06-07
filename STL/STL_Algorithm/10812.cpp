// https://www.acmicpc.net/problem/10812
// Name: 바구니 순서 바꾸기
// Topic: stl algorithm

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);

    while(m--) {
        int begin, end, mid;
        cin >> begin >> end >> mid;
        auto it = v.begin() - 1;
        rotate(it + begin, it + mid, it + end + 1);
    }

    for (auto x : v) cout << x << ' ';
}