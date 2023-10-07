#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d:%d", &N, &M);
    printf("%d:%d", N / gcd(N, M), M / gcd(N, M));

    return 0;
}
