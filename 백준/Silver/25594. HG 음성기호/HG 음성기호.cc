#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> result;
    string str;
    string HG_passward[27] = { "aespa","baekjoon","cau","debug","edge","firefox",
     "golang","haegang","iu","java","kotlin","lol","mips" ,"null","os","python"
    , "query", "roka","solvedac","tod","unix","virus","whale","xcode","yahoo","zebra" };
    long long len = 0;
    long long idx = 0;

    cin >> str;
    len = str.length();
    
    while (idx != len)
    {
        if (str.find(HG_passward[str[idx] - 'a']) != string::npos)
        {
            result.push_back(str[idx]);
            idx += HG_passward[str[idx] - 'a'].length();
        }
        else
        {
            cout << "ERROR!";
            return 0;
        }
    }

    cout << "It's HG!\n";
    for (char item : result)
    {
        cout << item;
    }

    return 0;
}