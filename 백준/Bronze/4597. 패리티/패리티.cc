#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;

    
    while (1)
    {
        cin >> str;

        if (str == "#")
            break;

        if (str[str.length() - 1] == 'e' && count(str.begin(), str.end(), '1') % 2 == 0)
            str[str.length() - 1] = '0';
        else if (str[str.length() - 1] == 'e' && count(str.begin(), str.end(), '1') % 2 != 0)
            str[str.length() - 1] = '1';
        else if (str[str.length() - 1] == 'o' && count(str.begin(), str.end(), '1') % 2 == 0)
            str[str.length() - 1] = '1';
        else if (str[str.length() - 1] == 'o' && count(str.begin(), str.end(), '1') % 2 != 0)
            str[str.length() - 1] = '0';

        cout << str << "\n";
    }
    
	return 0;
}