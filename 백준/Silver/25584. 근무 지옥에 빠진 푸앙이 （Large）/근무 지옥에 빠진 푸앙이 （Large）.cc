#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> m;

    string str;
    int week_num = 0;
    int max = -1000000001;
    int min = 1000000001;
    int time[4] = { 4,6,4,10 };

    cin >> week_num;

    for (int i = 0; i < week_num; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                cin >> str;
                if (str == "-")
                    continue;
                else
                    m[str] += time[j];     
            }
        }
    }

    for (auto item : m)
    {
        if (max < item.second)
        {
            max = item.second;
        }

        if (min > item.second)
        {
            min = item.second;
        }
    }

    if (max - min > 12)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}