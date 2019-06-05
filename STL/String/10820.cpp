// https://www.acmicpc.net/problem/10820
// Name: 문자열 분석
// Topic: string

#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        int lower = 0, upper = 0, num = 0, blank = 0;
        for (auto x : s) {
            if (islower(x)) lower++;
            else if (isupper(x)) upper++;
            else if (isdigit(x)) num++;
            else if (isblank(x)) blank++;
        }
        cout << lower << ' ' << upper << ' ' << num << ' ' << blank << '\n';
    }
}