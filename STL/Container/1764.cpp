// https://www.acmicpc.net/problem/1764
// Name: 듣보잡
// Topic: stl container(set, unordered set)

#include <iostream>
#include <string.h>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<string> name_set;
    while(n--) {
        string name;
        cin >> name;
        name_set.insert(name);
    }

    set<string> answer;
    while(m--) {
        string name;
        cin >> name;
        if (name_set.count(name)) answer.insert(name);
    }

    cout << answer.size() << '\n';
    for (auto x : answer) {
        cout << x << '\n';
    }

    return 0;
}