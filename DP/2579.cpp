// https://www.acmicpc.net/problem/2579
// Name: 계단 오르기
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> stair;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        stair.push_back(temp);
    }

    vector<int> v(num);
    v[0] = stair[0], v[1] = stair[0] + stair[1], v[2] = max(stair[0]+stair[2], stair[1] + stair[2]);
    for (int i = 3; i < num; i++) {
        v[i] = max(v[i - 2] + stair[i], v[i - 3] + stair[i - 1] + stair[i]);
    }
    cout << v[num - 1];
}