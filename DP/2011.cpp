// https://www.acmicpc.net/problem/2011
// Name: 암호 코드
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    if(num[0] == '0' || (num[1] == '0' && num[0] != '1' && num[0] != '2')) {
        cout << 0;
        return 0;
    }

    int len = num.length();
    vector<int> v(len, 0);
    v[0] = 1, v[1] = 2;
    if(num[1] == '0' || num[0] * 10 + num[1] > 26 + '0' * 11) v[1] = 1;
    for(int i = 2; i < len; i++) {
        if(num[i] == '0' && num[i - 1] != '1' && num[i - 1] != '2') {
            cout << 0;
            return 0;
        }
        if(num[i] == '0' && (num[i - 1] == '1' || num[i - 1] == '2')) {
            v[i] = v[i - 2];
            continue;
        }
        v[i] = v[i - 1];
        if(num[i - 1] != '0' && num[i] != '0' && num[i - 1] * 10 + num[i] <= 26 + '0' * 11) v[i] += v[i - 2];
        v[i] %= 1000000;
    }
    cout << v[len - 1];
}