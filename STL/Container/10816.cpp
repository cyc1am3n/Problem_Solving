// https://www.acmicpc.net/problem/10816
// Name: 숫자 카드 2
// Topic: stl container(unordered map)

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int num;
    cin >> num;
    unordered_map<int, int> map;
    while(num--) {
        int x;
        scanf("%d", &x);

        if(map.count(x)) map[x]++;
        else map[x] = 1;
    }

    int question_num;
    cin >> question_num;
    while(question_num--) {
        int x, ans;
        scanf("%d", &x);

        if(map.count(x)) ans = map[x];
        else ans = 0;

        printf("%d ", ans);
    }

    return 0;
}