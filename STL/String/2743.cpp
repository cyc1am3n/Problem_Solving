// https://www.acmicpc.net/problem/2743
// Name: 단어 길이 재기
// Topic: string

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string s;
    int num = 0;
    getline(cin, s);
    for (auto x : s) num++;
    cout << num;
    //cout << s.length(); 도 가능하다.
}