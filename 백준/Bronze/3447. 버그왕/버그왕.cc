#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

string str;
string find_str = "BUG";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (getline(cin, str))
    {
        while(str.find("BUG") != string::npos)
            str = regex_replace(str, regex("BUG"), "");

        cout << str << "\n";
    }

    return 0;
}