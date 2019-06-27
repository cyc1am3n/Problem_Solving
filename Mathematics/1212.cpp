// https://www.acmicpc.net/problem/1212
// Name: 8진수 2진수
// Topic: Mathematics

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string oct;
    cin >> oct;
    int len = oct.length();
    stack<int> s;
    for(int i = len - 1; i >= 0; i--) {
        int temp = oct[i] - '0', cnt = 0;
        while(cnt < 3) {
            s.push(temp % 2);
            temp /= 2;
            cnt++;
            if(i == 0 && temp == 0) break;
        }
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}