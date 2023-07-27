#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, K;
int mem[100001];
int arr[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(mem, mem + 100001, INF);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        mem[arr[i]] = 1;
    }

    mem[0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = arr[i]; j <= K; j++)
            mem[j] = min(mem[j], mem[j - arr[i]] + 1);


    if (mem[K] == INF)
        cout << -1;
    else
        cout << mem[K];


    return 0;
}
