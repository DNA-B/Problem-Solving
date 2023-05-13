#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string arr[51][5];
int min_value = 1000;
int ans1, ans2;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];


    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int cnt = 0;

            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 7; l++)
                {
                    if (arr[i][k][l] != arr[j][k][l])
                        cnt++;
                }
            }

            if (cnt < min_value)
            {
                ans1 = i;
                ans2 = j;
                min_value = cnt;
            }
        }
    }

    cout << ans1 + 1 << " " << ans2 + 1;

    return 0;
}