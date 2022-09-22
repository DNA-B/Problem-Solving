#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> m;
    map<string, int>::iterator it;

    string str;
    int week_num = 0;
    int max = -1;
    int min = 10001;

    cin >> week_num;

    for (int i = 0; i < week_num; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 7; i++)
            {
                cin >> str;
                if (str == "-")
                    continue;
                else
                {
                    if (m.find(str) == m.end())
                    {
                        if (j == 0)
                        {
                            m.insert({ str, 4 });
                        }
                        else if (j == 1)
                        {
                            m.insert({ str, 6 });
                        }
                        else if (j == 2)
                        {
                            m.insert({ str, 4 });
                        }
                        else
                        {
                            m.insert({ str, 10 });
                        }
                    }
                    else
                    {
                        it = m.find(str);
                        if (j == 0)
                        {
                            it->second += 4;
                        }
                        else if (j == 1)
                        {
                            it->second += 6;
                        }
                        else if (j == 2)
                        {
                            it->second += 4;
                        }
                        else
                        {
                            it->second += 10;
                        }
                    }
                }
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