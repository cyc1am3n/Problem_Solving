// https://www.acmicpc.net/problem/1158
// Name: 조세퍼스 문제
// Topic: stl container(queue)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q_size, k, num;
    cin >> q_size >> k;
    queue<int> q;
    for (int i = 1; i <= q_size; i++) q.push(i);

    cout << '<';

    while (!q.empty()) {
        int it = 1;
        while (it != k) {
            num = q.front();
            q.pop();
            q.push(num);
            it++;
        }
        num = q.front();
        cout << num;
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << '>';

    return 0;
}