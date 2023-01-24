#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    int n;

    cin >> n;

    while (n--)
    {
        cin >> str;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] + 32;
        }

        cout << str << "\n";
    }
    
	return 0;
}