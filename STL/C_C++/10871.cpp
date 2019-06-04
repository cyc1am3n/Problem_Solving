// https://www.acmicpc.net/problem/10871
// Name: X 보다 작은 수

#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    auto  is_less = [&](int num){
        return num < x;
    };

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (is_less(temp)) {
            cout << temp << ' ';
        }
    }
}