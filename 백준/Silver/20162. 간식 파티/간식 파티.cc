#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int arr[1001];
int mem[1001];
int ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        mem[i] = arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
                mem[i] = max(mem[i], mem[j] + arr[i]);
        }
        ans = max(ans, mem[i]);
    }

    cout << ans;

    return 0;
}
