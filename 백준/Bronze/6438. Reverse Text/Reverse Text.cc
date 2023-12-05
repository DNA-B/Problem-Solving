#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin.ignore();

    while (N--)
    {
        getline(cin, s);
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }

    return 0;
}