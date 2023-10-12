#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N;
map<string, string> m;

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
    }

    cout << (--m.end())->second << "\n";
    cout << m.begin()->second;

    return 0;
}
