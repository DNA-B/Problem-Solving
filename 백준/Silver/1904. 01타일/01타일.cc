#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
long long mem[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    mem[1] = 1;
    mem[2] = 2;
    for (int i = 3; i <= N; i++)
        mem[i] = (mem[i - 1] % 15746) + (mem[i - 2] % 15746);

    cout << mem[N] % 15746;

    return 0;
}
