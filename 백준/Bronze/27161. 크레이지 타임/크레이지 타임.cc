#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<string, int> p;
    int cur_time = 1;
    bool is_reverse = false;
    bool is_equal = false;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;

        if (p.first == "HOURGLASS")
        {
            if (p.second != cur_time)
                is_reverse = !is_reverse;
        }

        if (p.second == cur_time)
        {
            if (p.first != "HOURGLASS")
                is_equal = true;
        }

        if (is_equal)
        {
            cout << cur_time << " YES" << "\n";
            is_equal = false;
        }
        else
        {
            cout << cur_time << " NO" << "\n";
        }
      
        if (is_reverse)
        {
            if (cur_time - 1 == 0)
                cur_time = 12;
            else
                cur_time--;
        }
        else
        {
            if (cur_time + 1 == 13)
                cur_time = 1;
            else
                cur_time++;
        } 
    }

    return 0;
}