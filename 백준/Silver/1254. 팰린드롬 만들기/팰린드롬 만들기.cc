#include <bits/stdc++.h>

using namespace std;

string str;
string tmp;
bool flag;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        // 양 쪽 끝에서 부터 부분문자열이 팰린드롬인 곳의 위치를 찾고 그만큼 뒤에 붙여주면 된다.
        tmp = str.substr(i, str.length() - i);
        flag = true;

        for (int j = 0; j < tmp.length() / 2; j++)
        { // 절반만 확인하면 됌
            if (tmp[j] != tmp[(tmp.length() - 1) - j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans = str.length() + i;
            break;
        }
    }

    cout << ans;

    return 0;
}