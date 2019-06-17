// https://www.acmicpc.net/problem/9465
// Name: 스티커
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
    while(num--) {
        int n;
        cin >> n;
        vector<vector<int>> s;
        for(int i = 0; i < 2; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                int score;
                cin >> score;
                temp.push_back(score);
            }
            s.push_back(temp);
        }

        vector<vector<int>> v;
        v.assign(n, vector<int>(3, 0)); // 0: select nothing, 1: select top, 2: select bottom
        v[0][1] = s[0][0], v[0][2] = s[1][0];
        for(int i = 1; i < n; i++) {
            v[i][0] = max({v[i - 1][0], v[i - 1][1], v[i - 1][2]});
            v[i][1] = max(v[i - 1][0], v[i - 1][2]) + s[0][i];
            v[i][2] = max(v[i - 1][0], v[i - 1][1]) + s[1][i];
        }
        int ans = max({v[n - 1][0], v[n - 1][1], v[n - 1][2]});
        cout << ans << '\n';
    }
}