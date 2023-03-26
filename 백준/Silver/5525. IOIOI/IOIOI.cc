#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int cur = 0;
    int ans = 0;
    string str;
    string ioi = "";

    cin >> N >> M >> str;

    for (int i = 0; i < 2 * N + 1; i++)
    {
        if (i % 2 == 0)
            ioi += 'I';
        else
            ioi += 'O';
    }

    for (int i = 0; i <= M - (2 * N + 1); i++)
    {
        if (str.substr(i, (2 * N + 1)) == ioi)
            ans++;
    }

    cout << ans;

    return 0;
}