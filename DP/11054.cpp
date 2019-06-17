// https://www.acmicpc.net/problem/11054
// Name: 가장 긴 바이토닉 부분 수열
// Topic: Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> A;
    for(int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    vector<int> inc(num, 1), dec(num, 1);
    for(int i = 1; i < num; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(A[i] > A[j] && inc[j] + 1 > inc[i]) inc[i] = inc[j] + 1;
        }
    }
    for(int i = num - 2; i >= 0; i--) {
        for(int j = i + 1; j < num; j++) {
            if(A[i] > A[j] && dec[j] + 1 > dec[i]) dec[i] = dec[j] + 1;
        }
    }
    vector<int> byt(num, 0);
    for(int i = 0; i < num; i++) {
        byt[i] = inc[i] + dec[i] - 1;
    }
    int max = *max_element(byt.begin(), byt.end());
    cout << max;
}