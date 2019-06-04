// https://www.acmicpc.net/problem/10828
// Name: 스택
// Topic: stl container(stack)

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
    int num;
    cin >> num;

    stack<int> s;
    while(num--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (cmd == "pop") {
            if(s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (cmd == "size") cout << s.size() << '\n';
        else if (cmd == "empty") cout << s.empty() << '\n';
        else if (cmd == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }

    return 0;
}