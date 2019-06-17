// https://www.acmicpc.net/problem/2193
// Name: 이친수
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    if (num == 1) cout << 1;
    else {
        vector<vector<long>> v = {{0, 0, 1}}; // end with 00, 01, 10
        for (int i = 1; i < num - 1; i++) {
            v.push_back({0, 0, 0});
            v[i][0] = v[i - 1][0] + v[i - 1][2];
            v[i][1] = v[i - 1][0] + v[i - 1][2];
            v[i][2] = v[i - 1][1];
        }
        long sum = 0;
        for(auto x : v[num - 2]) sum += x;
        cout << sum;
    }
}