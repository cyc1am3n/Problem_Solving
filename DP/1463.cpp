// https://www.acmicpc.net/problem/1463
// Name: 1로 만들기
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int makeOne(vector<int> &v, int n) {
    int temp;
    if (v[n] != -1) return v[n];

    if (n > 1) {
        temp = makeOne(v, n-1);
        v[n] = temp + 1;
    }
    if (n % 3 == 0) {
        temp = makeOne(v, n/3);
        if (v[n] > temp + 1 ) v[n] = temp + 1;
    }
    if (n % 2 == 0) {
        temp = makeOne(v, n/2);
        if (v[n] > temp + 1) v[n] = temp + 1;
    }
    return v[n];
}

int top_down() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 0;
    cout << makeOne(v, num);
}

int bottom_up() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 0;
    for (int i = 2; i <= num; i++) {
        int temp = v[i - 1] + 1;
        if (i % 2 == 0)
            if (temp > v[i/2] + 1) temp = v[i/2] + 1;
        if (i % 3 == 0)
            if (temp > v[i/3] + 1) temp = v[i/3] + 1;
        v[i] = temp;
    }
    cout << '\n' << v[num];
}