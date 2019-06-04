// https://www.acmicpc.net/problem/1076
// Name: 저항
// Topic: stl container(map)

#include <iostream>
#include <map>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    map<int, long long int> map;
    for (int i = 0; i < 10; i++) {
        map.insert({i, pow(10, i)});
    }

    long long answer;

    for (int n = 0; n < 3; n++) {
        string resist;
        cin >> resist;
        int key;

        if (resist == "black") key = 0;
        else if (resist == "brown") key = 1;
        else if (resist == "red") key = 2;
        else if (resist == "orange") key = 3;
        else if (resist == "yellow") key = 4;
        else if (resist == "green") key = 5;
        else if (resist == "blue") key = 6;
        else if (resist == "violet") key = 7;
        else if (resist == "grey") key = 8;
        else if (resist == "white") key = 9;

        if (n == 0) answer = key * 10;
        else if (n == 1) answer += key;
        else if (n == 2) answer *= map[key];
    }

    cout << answer;

    return 0;
}