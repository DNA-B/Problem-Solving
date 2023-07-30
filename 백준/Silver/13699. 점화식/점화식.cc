#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
long long mem[36];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    mem[0] = 1;
    mem[1] = 1;

    for (int i = 2; i <= N; i++)
    {

        long long tmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (j == (i - 1) - j) // 홀수
                tmp += mem[j] * mem[j];
            else // 짝수
                tmp += mem[j] * mem[(i - 1) - j];
        }

        mem[i] = tmp;
    }

    cout << mem[N];

    return 0;
}
