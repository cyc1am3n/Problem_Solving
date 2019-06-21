// https://www.acmicpc.net/problem/2133
// Name: 타일 채우기
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    if (num % 2 != 0) {
        cout << 0;
        return 0;
    }
    vector<int> v(num / 2 + 1, 0);
    v[0] = 1, v[1] = 3;
    for(int i = 2; i <= num / 2; i++) {
        v[i] = v[i - 1] * 3;
        for(int j = i - 2; j >= 0; j--) {
            v[i] += v[j] * 2;
        }
    }

    cout << v[num / 2];
}