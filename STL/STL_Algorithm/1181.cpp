// https://www.acmicpc.net/problem/1181
// Name: 단어 정렬
// Topic: stl algorithm

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> v;
    while(n--) {
        string word;
        cin >> word;
        v.push_back(word);
    }

    sort(v.begin(), v.end(), [](string word1, string word2) {
        if(word1.length() == word2.length()) return word1 < word2;
        else return word1.length() < word2.length();
    });

    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());

    for(auto x : v) cout << x << '\n';
}