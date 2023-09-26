#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;
bool is_possible = true;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int k;
        int prev = -1;

        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int x;

            cin >> x;

            if (prev == -1)
            {
                prev = x;
                continue;
            }

            if (x > prev)
                is_possible = false;
            else
                prev = x;
        }
    }

    if (is_possible)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
