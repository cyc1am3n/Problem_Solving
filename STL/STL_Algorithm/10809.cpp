// https://www.acmicpc.net/problem/10809
// Name: 알파벳 찾기
// Topic: stl container

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i <= char('z' - 'a'); i++) {
        auto it = find(s.begin(), s.end(), char('a' + i));
        if (it == s.end()) cout << -1 << ' ';
        else cout << it - s.begin() << ' ';
    }
}