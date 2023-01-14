#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;
    string str;
    
    cin >> str;

    for (int i = 0; i < str.length(); i++)
        v.push_back(str.substr(0 + i, str.length()));

    sort(v.begin(), v.end());

    for (string item : v)
        cout << item << "\n";

    return 0;
}