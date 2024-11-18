#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    int n, rainbow_dance = 1; // 총총이 1명 고정
    string s1, s2;
    map <string, int> name;

    name["ChongChong"]++;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s1 >>s2;
 
        if (name.find(s1) != name.end() && name.find(s2) == name.end()) { // s1이 무지개댄스, s2는 x
            name[s2]++;
            rainbow_dance++;
        }
        else if(name.find(s2) != name.end() && name.find(s1) == name.end()) { // s2가 무지개댄스, s1는 x
            name[s1]++;
            rainbow_dance++;
        }
        // 둘 다 무지개댄스면 카운트 X
        // 둘 다 X여도 카운트 X
    }
    
    cout << rainbow_dance;
}