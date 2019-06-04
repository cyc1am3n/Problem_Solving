// Created by Daeyoung on 2019-05-22.
// https://www.acmicpc.net/problem/10866
// Name: 덱

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> d;
    while (n--) {
        string cmd;
        int num;
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> num;
            d.push_front(num);
        }
        else if (cmd == "push_back") {
            cin >> num;
            d.push_back(num);
        }
        else if (cmd == "pop_front") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << d.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << d.empty() << '\n';
        }
        else if (cmd == "front") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.front() << '\n';
            }
        }
        else if (cmd == "back") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.back() << '\n';
            }
        }
    }

    return 0;
}
