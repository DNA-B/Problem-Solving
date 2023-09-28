#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int ans = 0;
map<string, int> m; // {닉네임, 채팅횟수}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        string tmp;

        cin >> tmp;

        if (tmp == "ENTER")
        {
            m = {};
            continue;
        }

        m[tmp]++;

        if (m[tmp] == 1)
            ans++;
    }

    cout << ans;

    return 0;
}
