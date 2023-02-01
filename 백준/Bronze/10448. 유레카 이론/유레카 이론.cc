#include <bits/stdc++.h>

using namespace std;

vector<int> v(1001);
int t, k;

void samgaksoo()
{
    for (int i = 1; i <= 1000; i++)
        v[i] = (i * (i + 1)) / 2;   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> t;

    samgaksoo();

    while (t--)
    {
        bool is_samgak = false;
        cin >> k;

        for (int i = 1; i < k; i++)
        {
            for (int j = 1; j < k; j++)
            {
                for (int q = 1; q < k; q++)
                {
                    if (v[i] + v[j] + v[q] == k)
                    {
                        is_samgak = true; 
                        break; // q : break
                    }
                }
                if (is_samgak) // j : break
                    break;
            }
            if (is_samgak) // i : break
                break;
        }

        if (is_samgak)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}