// https://www.acmicpc.net/problem/11651
// Name: 좌표 정렬하기 2
// Topic: stl algorithm

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair <int, int>> v;

    while(n--) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        else return p1.second < p2.second;
    });

    for (auto x : v) cout << x.first << ' ' << x.second << '\n';
}