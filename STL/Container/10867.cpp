// https://www.acmicpc.net/problem/10867
// Name: 중복 빼고 정렬하기
// Topic: stl container(set)

#include <iostream>
#include <set>
using namespace std;

int main() {
    int num;
    cin >> num;
    set<int> set;
    while(num--) {
        int temp;
        cin >> temp;
        set.insert(temp);
    }

    for (int x : set) {
        cout << x << ' ';
    }

    return 0;
}