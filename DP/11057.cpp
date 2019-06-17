// https://www.acmicpc.net/problem/11057
// Name: 오르막 수
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<vector<int>> v = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    for (int i = 1; i < num; i++) {
        v.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
        for (int p = 0; p < 10; p++) {
            for (int q = p; q < 10; q++) {
                v[i][q] = (v[i][q] + v[i - 1][p]) % 10007;
            }
        }
    }
    int sum = 0;
    for (auto x : v[num - 1]) sum += x;
    cout << sum % 10007;
}