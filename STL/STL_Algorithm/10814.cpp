// https://www.acmicpc.net/problem/10814
// Name: 나이 순 정렬
// Topic: stl algorithm

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Member {
    string name;
    int age;
};

bool cmp(const Member &m1, const Member &m2) {
    return m1.age < m2.age;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<Member> v(num);

    for (int i = 0; i < num; i++) {
        int age;
        string name;
        cin >> age >> name;
        v[i].name = name, v[i].age = age;
    }

    stable_sort(v.begin(), v.end(), cmp);
    for(auto x : v) cout << x.age << ' ' << x.name << '\n';
}

struct other_Member {
    string name;
    int age;
    int join;
};

bool other_cmp(const other_Member &m1, const other_Member &m2) {
    if (m1.age == m2.age) return m1.join < m2.join;
    else return m1.age < m2.age;
}

void other_solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<other_Member> v(num);

    for (int i = 0; i < num; i++) {
        int age;
        string name;
        cin >> age >> name;
        v[i].name = name, v[i].age = age, v[i].join = i;
    }

    sort(v.begin(), v.end(), other_cmp);
    for(auto x : v) cout << x.age << ' ' << x.name << '\n';
}