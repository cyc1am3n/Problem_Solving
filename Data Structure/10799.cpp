// https://www.acmicpc.net/problem/10799
// Name: 쇠막대기
// Topic: stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string brackets;
    cin >> brackets;
    stack<int> s;
    int iron = 0, index = 0;
    for (auto x : brackets) {
        if (x == '(') s.push(index);
        else {
            if (s.top() == index - 1) iron += s.size() - 1;
            else iron++;
            s.pop();
        }
        index++;
    }
    cout << iron;
}