// https://www.acmicpc.net/problem/11656
// Name: 접미사 배열
// Topic: string

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.length(); i++) {
        v.push_back(s.substr(i));
    }
    sort(v.begin(), v.end());

    for (auto x : v) cout << x << '\n';
}