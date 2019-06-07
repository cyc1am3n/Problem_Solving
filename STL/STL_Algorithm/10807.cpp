// https://www.acmicpc.net/problem/10807
// Name: 개수 세기
// Topic: stl algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> v;
    scanf("%d", &n);
    while(n--) {
        int temp;
        scanf("%d", &temp);
        v.emplace_back(temp);
    }
    int m;
    scanf("%d", &m);
    printf("%d", count(v.begin(), v.end(), m));
}