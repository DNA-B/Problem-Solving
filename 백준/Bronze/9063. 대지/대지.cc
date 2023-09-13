#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int max_x = -INF, min_x = INF, max_y = -INF, min_y = INF;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x, y;

        cin >> x >> y;

        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
    }

    cout << (max_x - min_x) * (max_y - min_y);

    return 0;
}
