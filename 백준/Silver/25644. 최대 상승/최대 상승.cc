#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, x, ans = 0;
vector<int> v;
int max_num = -1;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        cin >> x;
        v.push_back(x);
    }
    
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] > max_num)
            max_num = v[i];

        ans = max(ans, max_num - v[i]);
    }

    cout << ans;

    return 0;
}