#include <bits/stdc++.h>

using namespace std;

string str;
int bd_cnt = 0;
int sec_cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;

    cin >> n;
    cin >> str;
    string tmp = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (tmp == "security")
        {
            sec_cnt++;
            tmp = "";
        }
        else if (tmp == "bigdata")
        {
            bd_cnt++;
            tmp = "";
        }
        tmp += str[i];
    }

    if (tmp == "security") // 마지막 단어 check
        sec_cnt++;
    else if (tmp == "bigdata")
        bd_cnt++;

    if (bd_cnt < sec_cnt) // print result
        cout << "security!";
    else if (bd_cnt > sec_cnt)
        cout << "bigdata?";
    else
        cout << "bigdata? security!";

    return 0;
}