#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> s;
        cout << ((s[s.size() - 1] - '0') % 2 == 0 ? "even\n" : "odd\n");
    }

    return 0;
}
