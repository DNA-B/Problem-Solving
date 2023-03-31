#include<bits/stdc++.h>

using namespace std;

long long mem[91];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;

    for (int i = 3; i <= N; i++)
        mem[i] = mem[i - 2] + mem[i - 1];

    cout << mem[N];

    return 0;
}