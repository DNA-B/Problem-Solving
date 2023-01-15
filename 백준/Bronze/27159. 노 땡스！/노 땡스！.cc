#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score = 0;
    vector<int> v;
    int n;
    
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    score += v[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] - v[i] != 1)
        {
            score += v[i + 1];
        }
    }

    cout << score;

    return 0;
}