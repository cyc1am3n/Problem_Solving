// https://www.acmicpc.net/problem/11655
// Name: ROT13
// Topic: string

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
    string s;
    getline(cin , s);
    for (auto x : s) {
        if (isupper(x)) cout << char('A' + (x - 'A' + 13) % ('Z' - 'A' + 1));
        else if (islower(x)) cout << char('a' + (x - 'a' + 13) % ('z' - 'a' + 1));
        else cout << x;
    }
}