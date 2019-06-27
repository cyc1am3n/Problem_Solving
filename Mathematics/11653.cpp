// https://www.acmicpc.net/problem/11653
// Name: 소인수분해
// Topic: Mathematics

#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    for(int i = 2; i * i <= num; i++) {
        while(num % i == 0) {
            cout << i << '\n';
            num /= i;
        }
    }
    if(num > 1) cout << num;
}