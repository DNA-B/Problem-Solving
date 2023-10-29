#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N, M;
long long acc[100001];
int p1 = 0, p2 = 1;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int x;

        cin >> x;
        acc[i] = acc[i - 1] + x;
    }

    while (p2 <= N)
    {
        if (acc[p2] - acc[p1] == M)
            cnt++;

        if (acc[p2] - acc[p1] <= M)
            p2++;
        else
            p1++;
    }

    cout << cnt;

    return 0;
}
