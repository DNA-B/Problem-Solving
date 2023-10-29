#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N, M;
int arr[10001];
int cur_sum = 0, cnt = 0;
int p1 = 0, p2 = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    while (p2 <= N)
    {
        if (cur_sum >= M)
            cur_sum -= arr[p1++];
        else
            cur_sum += arr[p2++];

        if (cur_sum == M)
            cnt++;
    }

    cout << cnt;

    return 0;
}
