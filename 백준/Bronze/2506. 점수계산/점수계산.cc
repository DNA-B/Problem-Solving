#include <bits/stdc++.h>

using namespace std;

int n;
int ox;
int score = 0;
int total = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> ox;

        if (ox == 1)
            score += 1;
        else
            score = 0;

        total += score;
    }

    cout << total;

    return 0;
}