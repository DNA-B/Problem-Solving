#include<bits/stdc++.h>

using namespace std;

vector<char> yonsei;
vector<char> korea;
string y = "YONSEI";
string k = "KOREA";
int py = 0;
int pk = 0;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == y[py])
        {
            yonsei.push_back(y[py]);
            py++;
        }

        if (str[i] == k[pk])
        {
            korea.push_back(k[pk]);
            pk++;
        }

        if (yonsei.size() == 6)
        {
            cout << "YONSEI";
            break;
        }

        if (korea.size() == 5)
        {
            cout << "KOREA";
            break;
        }
    }

    return 0;
}