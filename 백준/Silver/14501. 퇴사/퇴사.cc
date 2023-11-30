#include <bits/stdc++.h>
using namespace std;

int N;
int ans = 0;
int T[20], P[20];

void solve(int idx, int cur_time, int cur_price)
{
    if (idx > N)
        return;
    else
        ans = max(ans, cur_price);

    solve(idx + T[idx], cur_time + T[idx], cur_price + P[idx]); // 포함 O
    solve(idx + 1, cur_time, cur_price); // 포함 X
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(T, T + 20, N);

    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];

    solve(0, 0, 0);

    cout << ans;

    return 0;
}