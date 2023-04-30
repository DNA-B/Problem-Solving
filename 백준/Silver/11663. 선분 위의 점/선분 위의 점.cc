#include<bits/stdc++.h>

using namespace std;

int N, M;
int st, en;
int first, second;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    sort(arr, arr + N);

    for (int i = 0; i < M; i++) 
    {
        cin >> st >> en;

        first = lower_bound(arr, arr + N, st) - arr;
        second = upper_bound(arr, arr + N, en) - arr;

        cout << second - first << '\n';
    }

    return 0;
}