// https://www.acmicpc.net/problem/10808
// Name: 알파벳 개수
// Topic: stl algorithm

#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i <= int('z' - 'a'); i++) {
        cout << count(s.begin(), s.end(), char('a' + i)) << ' ';
    }
}

void other_solution() {
    string s;
    cin >> s;
    unordered_map<char, int> m;
    for (int i = 0; i <= int('z' - 'a'); i++) {
        m[char('a' + i)] = 0;
    }

    for (char x : s) {
        m[x]++;
    }

    for (int i = 0; i <= int('z' - 'a'); i++) {
        cout << m[char('a' + i)] << ' ';
    }
}