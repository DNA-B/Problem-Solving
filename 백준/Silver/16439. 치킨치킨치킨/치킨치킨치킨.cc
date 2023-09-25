#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;
int ans = -1;
int arr[31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
        

    for (int i = 0; i < M - 2; i++)
    {
        for (int j = i + 1; j < M - 1; j++)
        {
            for (int k = j + 1; k < M; k++)
            {
                int sum = 0;
                
                for (int z = 0; z < N; z++)
                    sum += max({ arr[z][i], arr[z][j], arr[z][k] });

                ans = max(ans, sum);
            }
        }
    }
    
    cout << ans;

    return 0;
}
