#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 1; i <= str.length(); i++)
    {
        cout << str[i - 1];

        if (i % 10 == 0)
            cout << "\n";
        
    }

    return 0;
}