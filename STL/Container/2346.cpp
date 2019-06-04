// https://www.acmicpc.net/problem/2346
// Name: 풍선 터트리기
// Topic: stl container(list)

#include <iostream>
#include <list>
using namespace std;

int main() {
    int num, value;
    list<pair<int,int>> list;
    cin >> num;
    int i = 1;
    while(num--) {
        cin >> value;
        list.emplace_back(make_pair(i++, value));
    }

    auto it = list.begin();
    while(list.size() != 1) {
        int step = it->second;
        cout << it->first << ' ';
        auto temp = it;

        if(step > 0) {
            temp++;
            if(temp == list.end()) temp = list.begin();
            list.erase(it);
            it = temp;
            while(--step){
                it++;
                if (it == list.end()) it = list.begin();
            }
        } else if(step < 0){
            step = -step;
            if(temp == list.begin()) temp = list.end();
            temp--;
            list.erase(it);
            it = temp;
            while(--step) {
                if(it == list.begin()) it = list.end();
                it--;
            }
        }
    }
    cout << list.front().first;
    return 0;
}