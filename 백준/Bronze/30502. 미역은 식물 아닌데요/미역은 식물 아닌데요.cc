#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int arr[1001][2];
int min_v = 0, max_v = 0;

void init()
{
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 2; j++)
            arr[i][j] = -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    init();

    for (int i = 0; i < M; i++)
    {
        int a, c;
        char b;

        cin >> a >> b >> c;

        if (b == 'P')
            arr[a][0] = c;
        else if (b == 'M')
            arr[a][1] = c;
    }

    for (int i = 1; i <= N; i++)
    {
        if (arr[i][0] == 1 && arr[i][1] == 0)
            min_v++;
        if ((arr[i][0] == 1 && arr[i][1] != 1) || (arr[i][0] != 0 && arr[i][1] == 0) || (arr[i][0] == -1 && arr[i][1] == -1))
            max_v++;
    }

    cout << min_v << " " << max_v;

    return 0;
}
