#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> v;
    int grade[51] = { 0 };
    int rep;
    int count = 1;
    int weight, height;

    cin >> rep;

    while (rep--)
    {
        cin >> weight >> height;
        v.push_back({ weight, height });
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (j == i)
            {
                continue;
            }
            else
            {
                if (v[i].first < v[j].first && v[i].second < v[j].second)
                { // 둘 다 작으면 상대가 나보다 큰 것이므로 등수가 밀린다.
                    count++;
                }
            }
        }
        grade[i] = count;
        count = 1;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << grade[i] << " ";
    }

    return 0;
}