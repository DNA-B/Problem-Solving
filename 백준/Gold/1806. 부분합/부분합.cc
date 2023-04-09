#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, S;
int min_len = INF;
int arr[100001];
int p1 = 0, p2 = 0, cur = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    while (p1 <= p2)
    {
        if (cur >= S)
        {
            min_len = min(min_len, p2 - p1);
            cur -= arr[p1];
            p1++;
        }
        else
        {
            if (p2 == N)
                break;

            cur += arr[p2];
            p2++;
        }
    }

    if (min_len == INF)
        cout << 0;
    else
        cout << min_len;

    return 0;
}