#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

long long mem[101];
int N;

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;
    mem[3] = 1;
    mem[4] = 2;
    mem[5] = 2;

    for (int i = 6; i <= 100; i++)
        mem[i] = mem[i - 1] + mem[i - 5];

    while (N--)
    {
        int x;

        cin >> x;
        cout << mem[x] << "\n";
    }

    return 0;
}