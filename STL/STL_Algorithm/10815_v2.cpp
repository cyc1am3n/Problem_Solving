// https://www.acmicpc.net/problem/10815
// Name: 숫자 카드
// Topic: stl algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long int> v(n);
    while(n--) {
        long long int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    while(m--) {
        long long int find_num;
        cin >> find_num;
        cout << binary_search(v.begin(), v.end(), find_num) << ' ';
    }
}