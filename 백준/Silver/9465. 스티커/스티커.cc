#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, N;
int arr[2][100001];
int mem[2][100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                cin >> arr[i][j];

        mem[0][0] = 0;
        mem[1][0] = 0;
        mem[0][1] = arr[0][1];
        mem[1][1] = arr[1][1];

        for (int j = 2; j <= N; j++)
        { 
            /*
            * 현재 위치로 오는 가지수가 2가지 있다.
            * 1. [내 대각선 방향][j-2] -> 2칸 뛰는 것 
            * 2. [내 대각선 방향][j-1] -> 1칸 뛰는 것
            * 이 중에서 max를 취하고 내 스티커 점수를 더하면 된다.
            */

            mem[0][j] = max(mem[1][j - 2], mem[1][j - 1]) + arr[0][j];
            mem[1][j] = max(mem[0][j - 2], mem[0][j - 1]) + arr[1][j];
        }

        cout << max(mem[0][N], mem[1][N]) << '\n';
    }

    return 0;
}
