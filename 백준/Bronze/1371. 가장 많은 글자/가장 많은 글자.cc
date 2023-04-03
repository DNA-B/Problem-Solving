#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int alp[27] = { 0 };
    string arr[51];
    int idx = 0;
    int max = -1;

    while (true)
    {
        getline(cin, arr[idx]);
        idx++;

        if (cin.eof())
            break;
    }

    for (int i = 0; i < idx; i++)
    {
        for (int j = 0; j < arr[i].length(); j++)
        {
            if (arr[i][j] == ' ')
                continue;

            alp[arr[i][j] - 'a'] += 1;
        }
    }

    for (int i = 0; i < 27; i++)
    {
        if (alp[i] > max)
            max = alp[i];
    }

    for (int i = 0; i < 27; i++)
    {
        if (alp[i] == max)
            cout << char(i + 'a');
    }

    return 0;
}