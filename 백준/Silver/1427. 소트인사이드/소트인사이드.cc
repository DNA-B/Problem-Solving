#include <bits/stdc++.h>

using namespace std;

vector<int> v(10);
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;

    for (int i = 0; i < str.length(); i++)
        v[i] = str[i] - '0';

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < str.length(); i++)
        cout << v[i];
    
    
    return 0;
}