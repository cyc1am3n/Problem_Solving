// https://www.acmicpc.net/problem/10818
// Name: 최소, 최대
// Topic: stl algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;

    while(n--) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    auto x = minmax_element(v.begin(), v.end());
    cout << *x.first << ' ' << *x.second;
}