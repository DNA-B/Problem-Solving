#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, m;
int find_num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cin >> m;
    while (m--)
    {
        cin >> find_num;

        if (binary_search(v.begin(), v.end(), find_num))
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}