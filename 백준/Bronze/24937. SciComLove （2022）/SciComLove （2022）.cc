#include <bits/stdc++.h>

using namespace std;

queue <char> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str = "SciComLove";
    int num;

    cin >> num;
    num %= 10;

    for (int i = 0; i < num; i++)
    {
        str += str[0];
        str.erase(str.begin());
    }

    cout << str;

    return 0;
}