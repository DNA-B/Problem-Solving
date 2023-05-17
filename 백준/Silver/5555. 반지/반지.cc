#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string str, ring;
int N;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> ring;

        if ((ring + ring).find(str) != string::npos)
            ans++;
    }

    cout << ans;

    return 0;
}