#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;

    cin >> str;

    if (str.substr(0, 3) != "555")
        cout << "NO";
    else
        cout << "YES";

    return 0;
}