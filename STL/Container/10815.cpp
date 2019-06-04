// https://www.acmicpc.net/problem/10815
// Name: 숫자 카드
// Topic: stl container

#include <iostream>
#include <map>
using namespace std;

int main() {
    int num;
    cin >> num;
    map<int, int> map;
    while(num--) { // 입출력시 cin / cout 사용하면 시간 초과
        int x;
        scanf("%d", &x);
        map[x] = 1;
    }

    int question_num;
    cin >> question_num;
    while(question_num--) {
        int x, ans;
        scanf("%d", &x);
        if(map.count(x)) ans = 1;
        else ans = 0;

        printf("%d ", ans);
    }

    return 0;
}