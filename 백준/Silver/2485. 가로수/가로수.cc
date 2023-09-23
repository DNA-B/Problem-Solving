#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int tmp = 0;
int ans = 0;
vector<int> diff;
vector<int> v;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;

        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size() - 1; i++)
        diff.push_back(v[i + 1] - v[i]);

    int tmp = diff[0];
    for (int i = 0; i < diff.size(); i++)
        tmp = gcd(diff[i], tmp);

    for (int i = v.front(); i <= v.back(); i += tmp)
        ans++;

    cout << ans - v.size();

    return 0;
}
