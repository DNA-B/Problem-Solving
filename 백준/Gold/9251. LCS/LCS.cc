#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int mem[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                mem[i][j] = mem[i - 1][j - 1] + 1;
            else
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
        }
    }

    cout << mem[s1.size()][s2.size()];
    return 0;
}
