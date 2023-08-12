#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int board[1001];
int mem[1001];
int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(mem, mem + 1001, INF);
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> board[i];

    mem[1] = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= board[i]; j++)
            mem[i + j] = min(mem[i + j], mem[i] + 1);

    if (mem[N] == INF)
        cout << -1;
    else
        cout << mem[N];

    return 0;
}
