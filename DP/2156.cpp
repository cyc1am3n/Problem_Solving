// https://www.acmicpc.net/problem/2156
// Name: 포도주 시식
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<int> drink;
    for(int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        drink.push_back(temp);
    }
    if(num < 3) {
        int sum = 0;
        for (auto x : drink) sum += x;
        cout << sum;
    }
    else {
        vector<vector<int>> v;
        v.assign(num, vector<int>(3, 0));
        v[0] = {0, drink[0], 0}, v[1] = {max({v[0][0], v[0][1], v[0][2]}), drink[1], v[0][1] + drink[1]};
        for (int i = 2; i < num; i++) {
            v[i] = {max({v[i - 1][0], v[i - 1][1], v[i - 1][2]}), v[i - 1][0] + drink[i], v[i - 2][0] + drink[i - 1] + drink[i]};
        }
        int ans = max({v[num - 1][0], v[num - 1][1], v[num - 1][2]});
        cout << ans;
    }
}