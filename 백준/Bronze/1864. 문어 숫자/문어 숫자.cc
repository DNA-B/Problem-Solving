#include <bits/stdc++.h>

using namespace std;

map<char, int> m = { {'-', 0}, {'\\', 1}, {'(', 2}, {'@', 3}, {'?', 4}, {'>', 5}, {'&', 6}, {'%', 7}, {'/', -1} };
string str;
long long res = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        res = 0;
        cin >> str;

        if (str == "#")
            break;

        for (int i = 0; i < str.length(); i++)
            res += m[str[i]] * (long long)pow(8, str.length() - (i + 1));

        cout << res << "\n";
    }
    


	return 0;
}