// https://www.acmicpc.net/problem/1373
// Name: 2진수 8진수
// Topic: Mathematics

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string bin;
    cin >> bin;
    int len = bin.length();
    stack<int> s;
    for(int i = len - 1; i >= 0; i -= 3) {
        if(i == 0) s.push(bin[0] - '0');
        else if(i == 1) s.push((bin[0] - '0') * 2 + bin[1] - '0');
        else s.push((bin[i - 2] - '0') * 4 + (bin[i - 1] - '0') * 2 + (bin[i] - '0'));
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}