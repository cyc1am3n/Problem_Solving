// https://www.acmicpc.net/problem/11576
// Name: Base Conversion
// Topic: Mathematics

#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main() {
    int from, to, len;
    cin >> from >> to >> len;
    long sum = 0;
    stack<int> s;
    for(int i = len - 1; i >= 0; i--) {
        int num;
        cin >> num;
        sum += long(num) * pow(from, i);
    }
    do {
        int r = sum % to;
        sum /= to;
        s.push(r);
    } while(sum != 0);
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}