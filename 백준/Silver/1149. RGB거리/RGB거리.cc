#include <bits/stdc++.h>

using namespace std;

int arr[1001][3];
int mem[1001][3];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    mem[1][0] = arr[1][0]; // R
    mem[1][1] = arr[1][1]; // G
    mem[1][2] = arr[1][2]; // B

    for (int i = 2; i <= n; i++)
    {
        mem[i][0] = min(mem[i - 1][1], mem[i - 1][2]) + arr[i][0]; // R이면 G,B에서 최소
        mem[i][1] = min(mem[i - 1][0], mem[i - 1][2]) + arr[i][1]; // G면 R,B에서 최소
        mem[i][2] = min(mem[i - 1][0], mem[i - 1][1]) + arr[i][2]; // B면 R,G에서 최소
    }

    cout << *min_element(mem[n], mem[n] + 3);

    return 0;
}