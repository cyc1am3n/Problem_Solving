// https://www.acmicpc.net/problem/11650
// Name: 좌표 정렬하기
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
       if (p1.first == p2.first) return p1.second < p2.second;
       else return p1.first < p2.first;
    });

    for (auto x : v) cout << x.first << ' ' << x.second << '\n';
}