// https://www.acmicpc.net/problem/11055
// Name: 가장 큰 증가하는 부분 수열
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> A, v;
    for(int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
        v.push_back(temp);
    }

    for(int i = 1; i < num; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(A[i] > A[j] && v[j] + A[i] > v[i]) v[i] = v[j] + A[i];
        }
    }
    int max = *max_element(v.begin(), v.end());
    cout << max;
}