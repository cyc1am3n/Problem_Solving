// https://www.acmicpc.net/problem/9613
// Name: GCD 합
// Topic: Mathematics

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int num;
        long long sum = 0;
        cin >> num;
        vector<int> v;
        while(num--) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        for(auto it = v.begin(); it != v.end() - 1; it++) {
            for(auto it2 = it + 1; it2 != v.end(); it2++) {
                sum += gcd(*it, *it2);
            }
        }
        cout << sum << '\n';
    }
}