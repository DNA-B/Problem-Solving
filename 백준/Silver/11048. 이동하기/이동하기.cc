#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/*
BOJ 11048번 : 이동하기
- x는 {+1, 0, +1}
- y는 {0, +1, +1}로 이동할 수 있다.
- 그렇다면 바텀업 방식으로 반대 방향을 생각할 수 있다.
- 즉, dx = {-1, 0, -1}, dy = {0, -1, -1}의 방향으로 움직이는 것이다.
- 그러면 3개의 방향에서 max값과 현재 위치의 사탕 개수를 더해주는 점화식을 만들 수 있다.
*/

int mem[1001][1001];
int arr[1001][1001];
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            mem[i][j] = max({ mem[i - 1][j], mem[i][j - 1], mem[i - 1][j - 1] }) + arr[i][j];

    cout << mem[N][M];

    return 0;
}