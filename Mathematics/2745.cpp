// https://www.acmicpc.net/problem/2745
// Name: 진법 변환
// Topic: Mathematics

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string s;
    int from;
    long sum = 0;
    cin >> s >> from;
    int strlen = s.length();
    for(int i = 0; i < strlen; i++) {
        if(s[i] >= 'A') sum += long(s[i] - 'A' + 10) * pow(from, (strlen - i - 1));
        else sum += long(s[i] - '0') * pow(from, (strlen - i - 1));
    }
    cout << sum;
}