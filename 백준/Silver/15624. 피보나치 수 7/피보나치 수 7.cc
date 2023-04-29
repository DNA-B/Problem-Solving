#include<bits/stdc++.h>

using namespace std;

long long mem[1000001];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    mem[0] = 0;
    mem[1] = 1;

    for (int i = 2; i <= N; i++)
        mem[i] = (mem[i - 2] % 1000000007) + (mem[i - 1] % 1000000007);

    cout << mem[N] % 1000000007;

    return 0;
}