#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, G, C, E;

    cin >> T;

    while (T--)
    {
        cin >> G >> C >> E;

        switch (G)
        {
        case 1:
            cout << (C < E ? (E - C) : 0);
            break;
        case 2:
            cout << (C < E ? 3 * (E - C) : 0);
            break;
        case 3:
            cout << (C < E ? 5 * (E - C) : 0);
            break;
        }
        cout << "\n";
    }

    return 0;
}