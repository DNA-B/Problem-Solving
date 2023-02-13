#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string fr;
    int n;
    int res = 0;

    cin >> str >> n;

    while (n--)
    {
        cin >> fr;

        if (str == fr)
            res++;
    }

    cout << res;

    return 0;
}