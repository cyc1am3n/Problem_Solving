// https://www.acmicpc.net/problem/9012
// Name: 괄호
// Topic: Stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    while(num--) {
        string brackets;
        cin >> brackets;
        stack<int> s;
        bool check = true;
        for (auto x : brackets) {
            if (x == '(') s.push(1);
            else{
                if(s.empty()) {
                    check = false;
                    break;
                } else s.pop();
            }
        }
        if(check && !s.empty()) check = false;

        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}