#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

vector<int> v;
int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (v.empty() || v.back() < x)
            v.push_back(x);
        else
            *lower_bound(v.begin(), v.end(), x) = x;
    }

    cout << v.size();

    return 0;
}
