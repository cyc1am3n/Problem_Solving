// https://www.acmicpc.net/problem/1929
// Name: 소수 구하기
// Topic: Mathematics

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int from, to;
    cin >> from >> to;
    vector<bool> v(to + 1, true);
    v[1] = false;
    for(int i = 2; i <= to; i++) {
        if(v[i]) {
            int ind = i * 2;
            while(ind <= to) {
                v[ind] = false;
                ind += i;
            }
        }
    }
    for(int i = from; i <= to; i++) {
        if(v[i]) cout << i << '\n';
    }
}