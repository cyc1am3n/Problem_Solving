// https://www.acmicpc.net/problem/1912
// Name: 연속 합
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<int> v;
    for(int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        if(i != 0)
            if(v[i - 1] > 0) v[i] += v[i - 1];
    }
    int max = *max_element(v.begin(), v.end());
    cout << max;
}