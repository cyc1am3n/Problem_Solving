// https://www.acmicpc.net/problem/2225
// Name: 합분해
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<long>> v;
    v.assign(K + 1, vector<long>(N + 1, 0));
    v[0][0] = 1;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j <= N; j++) {
            for(int l = 0; l <= j; l++) {
                v[i][j] += v[i - 1][j - l];
                v[i][j] %= 1000000000;
            }
        }
    }
    cout << v[K][N];
}