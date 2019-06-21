// https://www.acmicpc.net/problem/1699
// Name: 제곱수의 합
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> v(num + 1);
    v[0] = 0, v[1] = 1;
    for(int i = 2; i <= num; i++) {
        v[i] = i;
        for(int j = 1; j * j <= i; j++) {
            if(v[i] > v[i - j * j] + 1) v[i] = v[i - j * j] + 1;
        }
    }
    cout << v[num];
}