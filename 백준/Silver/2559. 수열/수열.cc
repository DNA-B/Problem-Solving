#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N, K;
int arr[100002];
int acc[100002];
int max_v = -INF;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        acc[i] = acc[i - 1] + arr[i];
    }
   
    for (int i = K; i <= N; i++)
        max_v = max(max_v, (acc[i] - acc[i - K]));

    cout << max_v;

    return 0;
}
