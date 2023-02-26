#include <bits/stdc++.h>

using namespace std;

string str;
int up = 0, lo = 0, dig = 0, sp = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1)
    {
        getline(cin, str);

        if (cin.eof())
            break;

        for (int i = 0; i < str.length(); i++)
        {
            if (islower(str[i]))
                lo++;
            else if (isupper(str[i]))
                up++;
            else if (isdigit(str[i]))
                dig++;
            else
                sp++;
        }   

        cout << lo << " " << up << " " << dig << " " << sp << "\n";
        
        up = 0;
        lo = 0;
        dig = 0;
        sp = 0;
    }

    return 0;
}