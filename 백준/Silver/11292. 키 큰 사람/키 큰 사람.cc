#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int N;
        vector<pair<string, double>> v;
        double max_h = -1;

        cin >> N;

        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
        {
            string name;
            double height;

            cin >> name >> height;

            max_h = max(max_h, height);
            v.push_back({ name, height });
        }

        for (int i = 0; i < N; i++)
            if (v[i].second == max_h)
                cout << v[i].first << " ";
        cout << "\n";
    }

    return 0;
}
