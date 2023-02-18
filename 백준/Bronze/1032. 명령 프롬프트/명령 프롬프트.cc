#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str[51];
    string answer = "";
    bool flag[51]; // 해당 자리가 모두 같은가 다른가 저장하는 배열
    int n;

    fill(flag, flag + 51, true);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> str[i];
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < str[i].length(); j++)
        {
            if (str[i - 1][j] != str[i][j]) // 다르면 flag의 해당 자리는 false
                flag[j] = false;
        }
    }

    for (int i = 0; i < str[0].length(); i++)
    {
        if (flag[i] == true) // 모두 같으면 flag의 해당 자리가 true일 것이므로 아무 문자열의 i번째 자리 추가
            answer += str[0][i];
        else // 하나라도 달랐다면 ? 추가
            answer += '?';
    }

    cout << answer;

    return 0;
}