// https://www.acmicpc.net/problem/10825
// Name: 국영수
// Topic: stl algorithm

#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int kor, eng, math;

    bool operator < (const Student &s) const {
        if (kor == s.kor) {
            if (eng == s.eng) {
                if (math == s.math) return name < s.name;
                else return math > s.math;
            } else return eng < s.eng;
        } else return kor > s.kor;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Student> v(n);
    for(int i = 0; i < n; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        v[i].name = name, v[i].kor = kor, v[i].eng = eng, v[i].math = math;
    }
    sort(v.begin(), v.end());
    for (auto x : v) cout << x.name << '\n';
}

void other_solution() {
    int n;
    cin >> n;
    vector<tuple<string, int, int, int>> v;

    while(n--) {
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        v.emplace_back(make_tuple(name, korean, english, math));
    }

    sort(v.begin(), v.end(), [](tuple<string, int, int, int> s1, tuple<string, int, int, int> s2) {
        if (get<1> (s1) == get<1> (s2)) {
            if (get<2> (s1) == get<2> (s2)) {
                if (get<3> (s1) == get<3> (s2)) return get<0> (s1) < get<0> (s2);
                else return get<3> (s1) > get<3> (s2);
            } else return get<2> (s1) < get<2> (s2);
        } else return get<1> (s1) > get<1> (s2);
    });

    for (auto x : v) cout << get<0> (x) <<'\n';
}