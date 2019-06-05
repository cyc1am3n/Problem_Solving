// https://www.acmicpc.net/problem/10821
// Name: 정수의 개수
// Topic: string

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string s;
    int num = 0;
    while(getline(cin, s, ','))
        num++;
    cout << num;
}