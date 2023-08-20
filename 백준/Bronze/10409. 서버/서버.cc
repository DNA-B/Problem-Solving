#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

int N, T;
int work_time[51];
int cur_time = 0;
int ans = 0;

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
       
    cin >> N >> T;

    for (int i = 0; i < N; i++)
    {
        cin >> work_time[i];

        if (cur_time + work_time[i] > T)
            break;

        cur_time += work_time[i];
        ans++;
    }

    cout << ans;

    return 0;
}