// https://www.acmicpc.net/problem/1406
// Name: 에티더
// Topic: stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string temp;
    cin >> temp;
    stack<char> left, right;
    for (auto x : temp) left.push(x);

    int num;
    cin >> num;
    while(num--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if(!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (cmd == 'D') {
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (cmd == 'B'){
            if (!left.empty()) left.pop();
        } else if (cmd == 'P') {
            char c;
            cin >> c;
            left.push(c);
        }
    }

    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }
}