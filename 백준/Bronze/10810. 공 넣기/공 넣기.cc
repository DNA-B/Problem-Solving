#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int arr[101];

int main() 
{
    cin >> N >> M;

    while (M--)
    {
        int x, y, z;

        cin >> x >> y >> z;

        for (int i = x; i <= y; i++)
            arr[i] = z;
    }

    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";

    return 0;
}