// https://www.acmicpc.net/problem/1978
// Name: 소수 찾기
// Topic: Mathematics

#include <iostream>
using namespace std;

bool prime(int n) {
    if(n < 2) return false;
    else if(n < 4) return true;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, cnt = 0;
    cin >> T;
    while(T--) {
        int num;
        cin >> num;
        if(prime(num)) cnt++;
    }
    cout << cnt;
}