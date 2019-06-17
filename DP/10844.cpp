// https://www.acmicpc.net/problem/10844
// Name: 쉬운 계단 수
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<vector<int>> v = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    for (int i = 1; i < num; i++) {
        v.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
        v[i][0] = v[i - 1][1];
        v[i][9] = v[i - 1][8];
        for (int j = 1; j < 9; j++) {
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % 1000000000;
        }
    }
    long sum = 0;
    for (auto x : v[num - 1]) sum += x;
    cout << sum % 1000000000;
}