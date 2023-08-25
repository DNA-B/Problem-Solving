#include <bits/stdc++.h>
#define npos string::npos

using namespace std;

vector<string> v = { "c=", "c-", "dz=" , "d-" , "lj" , "nj" , "s=" , "z=" };
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;

    for (int i = 0; i < v.size(); i++)
    {
        while(str.find(v[i]) != npos)
        {
            str.replace(str.find(v[i]), v[i].length(), "!");
        }
    }

    cout << str.length();

    return 0;
}