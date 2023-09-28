#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
long long mem[41];
int cnt1 = 0;

int fibo(int n) 
{
    if (n == 1 || n == 2) 
    {
        cnt1++;
        return 1;
    }
    
    return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fibo(N);

    mem[1] = mem[2] = 1;
    for (int i = 3; i <= N; i++)
        mem[i] = mem[i - 1] + mem[i - 2];

    cout << cnt1 << " " << N - 2;
    
    return 0;
}
