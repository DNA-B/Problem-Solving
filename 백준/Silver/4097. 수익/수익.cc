#include<bits/stdc++.h>

using namespace std;

int acc_sum[250001];
int arr[250001];
int N, T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> N;

        if (N == 0)
            break;

        fill(acc_sum, acc_sum + 250001, 0);
        fill(arr, arr + 250001, 0);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            acc_sum[i] = arr[i];
        }

        for (int i = 1; i < N; i++)
            acc_sum[i] = max(acc_sum[i], acc_sum[i - 1] + arr[i]);

        cout << *max_element(acc_sum, acc_sum + N) << "\n";
    }


    return 0;
}