#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

int z_flip(int n, int r, int c)
{
    int half;

    if (n == 0)
        return 0;
    
    // n이 3이라면 (2^2 * 2^2) 크기의 판을 2^2크기의 4구간으로 나눈다.
    half = 1 << (n - 1); // 비트연산 -> 2^(n-1)

    // 4개의 분할시킨 칸 (1, 2, 3, 4)
    if (r < half && c < half) // 1번 칸
        return z_flip(n - 1, r, c);
    if (r < half && c >= half) // 2번 칸(1개 지나감)
        return (half * half) + z_flip(n - 1, r, c - half);
    if (r >= half && c < half) // 3번 칸 (2개 지나감)
        return (2 * half * half) + z_flip(n - 1, r - half, c); 
    
    // 4번 칸 (3개 지나감)
    return (3 * half * half) + z_flip(n - 1, r - half, c - half);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;
    cout << z_flip(n, r, c);

    return 0;
}