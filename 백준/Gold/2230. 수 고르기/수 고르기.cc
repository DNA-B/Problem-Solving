#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;
int arr[100001];
int p1, p2;
int ans = INF;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    p1 = p2 = 0;
    while (p1 < N)
    {
        while (p2 < N && arr[p2] - arr[p1] < M)
            p2++;

        if (p2 == N)
            break;

        ans = min(ans, arr[p2] - arr[p1]);
        p1++;
    }

    cout << ans;

    return 0;
}
