#include <bits/stdc++.h>

using namespace std;

string str;
int res = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;

    for (auto item : str)
    {
        if (item == 'A' || item == 'B' || item == 'C')
            res += 3;
        else if (item == 'D' || item == 'E' || item == 'F')
            res += 4;
        else if (item == 'G' || item == 'H' || item == 'I')
            res += 5;
        else if (item == 'J' || item == 'K' || item == 'L')
            res += 6;
        else if (item == 'M' || item == 'N' || item == 'O')
            res += 7;
        else if (item == 'P' || item == 'Q' || item == 'R' || item == 'S')
            res += 8;
        else if (item == 'T' || item == 'U' || item == 'V')
            res += 9;
        else
            res += 10;
    }

    cout << res;

    return 0;
}