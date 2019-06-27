// https://www.acmicpc.net/problem/11005
// Name: 진법 변환 2
// Topic: Mathematics

#include <iostream>
#include <stack>
using namespace std;

int main() {
    long long num;
    int to, r;
    cin >> num >> to;
    stack<int> s;
    do {
        r = num % to;
        num /= to;
        s.push(r);
    } while(num != 0);

    while(!s.empty()) {
        int n = s.top();
        if(n > 9) cout << char('A' + n - 10);
        else cout << n;
        s.pop();
    }
}