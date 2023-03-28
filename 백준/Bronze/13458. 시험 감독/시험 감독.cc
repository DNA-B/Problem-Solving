#include<bits/stdc++.h>

using namespace std;

int arr[1000001];
int N, B, C;
long long ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    ans += N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> B >> C;

    for (int i = 0; i < N; i++)
        arr[i] -= B;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > 0)
            ans += int(ceil(arr[i] / (double)C));
    }

    cout << ans;

    return 0;
}