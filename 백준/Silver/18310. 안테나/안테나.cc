#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int arr[200001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    cout << arr[(N - 1) / 2];

    return 0;
}
