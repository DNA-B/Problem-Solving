#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int H, W, N, M;
long long ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W >> N >> M;


    ans = ((((H - 1) / (N + 1)) + 1) * (((W - 1) / (M + 1)) + 1));
    cout << ans;

    return 0;
}