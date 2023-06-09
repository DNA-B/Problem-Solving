#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

long long mem[1001];
const int DIV = 10007;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    mem[1] = 1;
    mem[2] = 3;
    
    for (int i = 3; i <= N; i++)
        mem[i] = (mem[i - 1] % DIV) + ((2 * mem[i - 2]) % DIV);

    cout << mem[N] % DIV;

    return 0;
}