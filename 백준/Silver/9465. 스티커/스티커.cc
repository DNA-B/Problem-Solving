#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, N;
int arr[2][1000001];
int mem[2][1000001][2]; // {행, 열, 뗐는지 안 뗐는지}

void init() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 2; k++)
                mem[i][j][k] = -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;

        init();

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                cin >> arr[i][j];

        mem[0][0][0] = 0; // X
        mem[1][0][0] = 0; // X
        mem[0][0][1] = arr[0][0]; // O
        mem[1][0][1] = arr[1][0]; // O

        for (int i = 1; i < N; i++)
        {
            mem[0][i][0] = max({ mem[0][i - 1][0], mem[1][i - 1][0], mem[0][i - 1][1], mem[1][i - 1][1] });
            mem[1][i][0] = max({ mem[0][i - 1][0], mem[1][i - 1][0], mem[0][i - 1][1], mem[1][i - 1][1] });
            mem[0][i][1] = max({ mem[0][i - 1][0] + arr[0][i], mem[1][i - 1][0] + arr[0][i], mem[1][i - 1][1] + arr[0][i], mem[0][i - 1][1] });
            mem[1][i][1] = max({ mem[0][i - 1][0] + arr[1][i], mem[1][i - 1][0] + arr[1][i], mem[0][i - 1][1] + arr[1][i], mem[1][i - 1][1] });
        }

        cout << max({ mem[0][N - 1][0], mem[0][N - 1][1], mem[1][N - 1][0], mem[1][N - 1][1] }) << "\n";
    }

    return 0;
}
