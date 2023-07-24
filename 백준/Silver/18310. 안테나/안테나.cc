#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int arr[200001];
int ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    double mid_value = 0;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    if (N % 2 == 0)
        mid_value = (arr[N / 2 - 1] + arr[N / 2]) / 2;
    else
        mid_value = arr[N / 2];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= mid_value)
            ans = arr[i];
    }

    cout << ans;

    return 0;
}
