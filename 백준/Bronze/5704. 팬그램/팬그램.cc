#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string str;
int alp[26];
bool is_pangram;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        fill(alp, alp + 26, 0);
        is_pangram = true;

        getline(cin, str);

        if (str == "*")
            break;

        for (auto item : str)
            alp[item - 'a'] += 1;

        for (int i = 0; i < 26; i++)
        {
            if (alp[i] == 0)
            {
                is_pangram = false;
                break;
            }
        }

        if (is_pangram)
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}
