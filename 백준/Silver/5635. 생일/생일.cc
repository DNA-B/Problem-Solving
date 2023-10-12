#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N;
map<string, string> m;
string max_v = "9999-99-99";
string min_v = "0000-00-00";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        string name, day, month, year;
        string tmp;

        cin >> name >> day >> month >> year;

        if (month.length() == 1)
            month = "0" + month;
        if (day.length() == 1)
            day = "0" + day;

        tmp = (year + "-" + month + "-" + day);
        m[tmp] = name;

        if (min_v < tmp)
            min_v = tmp;
        if (max_v > tmp)
            max_v = tmp;
    }

    for (auto item : m)
    {
        if (item.first == min_v)
            cout << item.second << "\n";
    }

    for (auto item :m)
    {
        if (item.first == max_v)
            cout << item.second << "\n";
    }

    return 0;
}
