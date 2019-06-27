// https://www.acmicpc.net/problem/6588
// Name: 골드바흐의 추측
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
    int num;
    cin >> num;
    while(num != 0) {
        bool flag = false;
        for(int i = 2; i <= num / 2; i++) {
            if(prime(i) && prime(num - i)) {
                cout << num << " = " << i << " + " << num - i << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << "Goldbach's conjecture is wrong.\n";
        cin >> num;
    }
}
