#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        int idx;
        string s;

        cin >> idx >> s;
        cout << s.erase(idx - 1, 1) << "\n";

    }

    return 0;
}
