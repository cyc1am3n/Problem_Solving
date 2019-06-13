// https://www.acmicpc.net/problem/11052
// Name: 카드 구매하기
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> P = {-1}, D = {-1};
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        P.push_back(cost);
        D.push_back(cost);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            D[i] = max(D[i], P[j] + D[i-j]);
        }
    }
    cout << D[n];
}