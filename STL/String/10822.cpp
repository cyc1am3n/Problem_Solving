// https://www.acmicpc.net/problem/10822
// Name: 더하기
// Topic: string

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string s;
    int sum = 0;
    while(getline(cin, s, ',')) {
        sum += stoi(s);
    }
    cout << sum;
}