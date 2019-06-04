// https://www.acmicpc.net/problem/1406
// Name: 에디터
// Topic: stl container(list)

#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    string s;
    int num;
    cin >> s;
    cin >> num;

    list<char> editor(s.begin(), s.end());
    auto cursor = editor.end();

    while(num--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor != editor.begin()) cursor--;
        } else if (cmd == 'D'){
            if (cursor != editor.end()) cursor++;
        } else if (cmd == 'B') {
            if (cursor != editor.begin()) {
                auto temp = cursor;
                --cursor;
                editor.erase(cursor);
                cursor = temp;
            }
        } else if(cmd == 'P') {
            char plus;
            cin >> plus;
            editor.insert(cursor, plus);
        }
    }

    for (char x : editor) {
        cout << x;
    }
    return 0;
}