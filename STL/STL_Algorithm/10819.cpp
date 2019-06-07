// https://www.acmicpc.net/problem/10819
// Name: 차이를 최대로
// Topic: stl algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v[i] = num;
    }

    sort(v.begin(), v.end());

    int max = 0;
    do {
        int temp = 0;
        for(int i = 1; i < n; i++) temp += abs(v[i] - v[i - 1]);
        if(temp > max) max = temp;
    } while(next_permutation(v.begin(), v.end()));

    cout << max;
}