#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
string name, order;
set<string, greater<string>> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> name >> order;

        if (order == "enter")
            s.insert(name);
        else if (order == "leave")
            s.erase(name);
    }

    for (auto item : s)
        cout << item << "\n";

    return 0;
}
