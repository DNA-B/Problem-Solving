#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define BOUND 0.15

using namespace std;

double N, ans = 0;
int trim_avg = 0;
int arr[300001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    trim_avg = round(N * BOUND);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + (int)N);

    for (int i = trim_avg; i < (int)N - trim_avg; i++)
        ans += arr[i];

    N -= 2 * trim_avg;
    cout << round(ans / N);

    return 0;
}
