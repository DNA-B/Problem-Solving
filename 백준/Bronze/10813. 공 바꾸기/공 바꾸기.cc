#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int arr[101];
int x, y;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        arr[i] = i;

    for (int i = 1; i <= M; i++)
    {
        cin >> x >> y;
        swap(arr[x], arr[y]);
    }

    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";

    return 0;
}