#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int arr[1001][6];
int inter[6];
int ans = 1;
bool flag = true;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 6; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = 0; k < 3; k++)
                if (!(arr[i][k + 3] > arr[j][k] && arr[j][k + 3] > arr[i][k]))
                    flag = false;

    if (flag == false)
    {
        cout << 0;
        return 0;
    }

    fill(inter, inter + 3, -1);
    fill(inter + 3, inter + 6, INF);
    
    for (int i = 0; i < 3; i++) // 왼쪽 아래
        for (int j = 0; j < N; j++)
            inter[i] = max(inter[i], arr[j][i]);

    for (int i = 3; i < 6; i++) // 오른쪽 위
        for (int j = 0; j < N; j++)
            inter[i] = min(inter[i], arr[j][i]);

    for (int i = 0; i < 3; i++)
        ans *= abs(inter[i] - inter[i + 3]);

    cout << ans;

    return 0;
}
