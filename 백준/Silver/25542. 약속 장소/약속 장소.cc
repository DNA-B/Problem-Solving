#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, L;
string arr[21];
string ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ans = arr[0];
    for (int i = 0; i < L; i++)
    {
        bool flag = false;
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            ans[i] = ch;
            bool too_diff = false;

            for (int j = 0; j < N; j++)
            {
                int cnt = 0;
                for (int k = 0; k < L; k++)
                {
                    if (ans[k] != arr[j][k])
                        cnt++;
                    if (cnt > 1)
                    {
                        too_diff = true;
                        break;
                    }
                }

                if (too_diff)
                    break;
            }

            if (!too_diff)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
            ans[i] = arr[0][i];
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < L; j++)
        {
            if (arr[i][j] != ans[j])
                cnt++;
        }

        if (cnt > 1)
        {
            cout << "CALL FRIEND";
            return 0;
        }
    }

    cout << ans;

    return 0;
}
