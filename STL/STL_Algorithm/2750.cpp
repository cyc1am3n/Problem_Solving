// https://www.acmicpc.net/problem/2750
// Name: 수 정렬하기
// Topic: stl algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;

    while(n--) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    for (auto x : v) cout << x << '\n';
}