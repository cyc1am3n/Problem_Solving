// https://www.acmicpc.net/problem/9461
// Name: 파도반 수열
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<long> v(100, 0);
    v[0] = 1, v[1] = 1, v[2] = 1, v[3] = 2, v[4] = 2;
    int cnt = 5;
    while(num--) {
        int temp;
        cin >> temp;
        if (temp > cnt){
            for (int i = cnt; i < temp; i++) v[i] = v[i - 1] + v[i - 5];
            cnt = temp;
        }
        cout << v[temp - 1] << '\n';
    }
}