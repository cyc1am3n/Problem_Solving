// https://www.acmicpc.net/problem/10823
// Name: 더하기 2
// Topic: string

#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

int main() {
    string s, temp;
    while(getline(cin, temp))
        s += temp;

    istringstream sin(s);

    string number;
    int sum = 0;
    while(getline(sin, number, ','))
        sum += stoi(number);

    cout << sum;
}