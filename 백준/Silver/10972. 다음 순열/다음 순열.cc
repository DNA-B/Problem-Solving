#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int arr[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (next_permutation(arr, arr + N))
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}