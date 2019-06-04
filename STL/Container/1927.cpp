// https://www.acmicpc.net/problem/1927
// Name: 최소 힙
// Topic: stl container(priority queue)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;
    while(n--) {
        int temp;
        scanf("%d", &temp);
        if (temp != 0) q.push(temp);
        else {
            if(q.empty()) printf("0\n");
            else {
                int num = q.top();
                printf("%d\n", num);
                q.pop();
            }
        }
    }

    return 0;
}