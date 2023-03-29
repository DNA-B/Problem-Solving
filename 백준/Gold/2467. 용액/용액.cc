#include<bits/stdc++.h>

using namespace std;

int N, p1, p2;
int arr[100001];
int v_min = 2000000003;
int idx1, idx2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    p1 = 0;
    p2 = N - 1;

    while (p1 < p2)
    {
        if (abs(arr[p1] + arr[p2]) < v_min)
        {
            idx1 = p1;
            idx2 = p2;
            v_min = abs(arr[p1] + arr[p2]);
        }

        if (abs(arr[p1]) > abs(arr[p2]))
            p1++;
        else
            p2--;
    }

    cout << arr[idx1] << " " << arr[idx2];
    

    return 0;
}