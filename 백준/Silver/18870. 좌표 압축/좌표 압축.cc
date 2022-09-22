#include <bits/stdc++.h>

using namespace std;

/*
- 좌표가 가지는 범위가 너무 커지면 낭비하는 메모리가 너무 커질수 있다.
- 그렇기 때문에 비어있는 공간을 압축하여 좌표값들만을 나타낸다.
*/

vector<int> crd;
vector<int> press;

int main() 
{ 
    int n;
    int x;
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cin >> x;
        press.push_back(x);
        crd.push_back(x);
    }
    
    // 정렬 후 중복 제거
    sort(press.begin(), press.end());
    press.erase(unique(press.begin(), press.end()), press.end());
    

    for (auto item : crd) 
    { // O(logN) 이진탐색
        cout << lower_bound(press.begin(), press.end(), item) - press.begin() << ' ';
    }

    return 0;
}