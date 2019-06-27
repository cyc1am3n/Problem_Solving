// https://www.acmicpc.net/problem/2089
// Name: -2진수
// Topic: Mathematics

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num;
    cin >> num;
    stack<int> s;
    do {
        int r;
        if(num < 0) {
            num *= -1;
            r = num % 2;
            num /= 2;
            if(r == 1) num++;
        } else {
            r = num % -2;
            num /= -2;
        }
        s.push(r);
    } while(num != 0);
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}