#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int ans = 0;
string skils;
map<char, int> prev_skils;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> skils;

    for (int i = 0; i < N; i++)
    {
        if ('1' <= skils[i] && skils[i] <= '9')
            ans++;

        if (skils[i] == 'L' || skils[i] == 'S')
            prev_skils[skils[i]]++;

        if (i > 0)
        {
            if (skils[i] == 'R')
            {
                if (prev_skils['L'] > 0)
                {
                    ans++;
                    prev_skils['L']--;
                }
                else
                    break;
            }

            if (skils[i] == 'K')
            {
                if (prev_skils['S'] > 0)
                {
                    ans++;
                    prev_skils['S']--;
                }
                else
                    break;
            }
        }
    }

    cout << ans;

    return 0;
}
