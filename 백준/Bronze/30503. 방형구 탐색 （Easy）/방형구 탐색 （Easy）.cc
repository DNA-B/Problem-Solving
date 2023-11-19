#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, Q;
int arr[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> Q;

    while (Q--)
    {
        int n, l, r, k;
        int cnt = 0;

        cin >> n;

        switch (n)
        {
        case 1:
            cin >> l >> r >> k;

            for (int i = l - 1; i < r; i++)
                if (arr[i] == k)
                    cnt++;

            cout << cnt << "\n";

            break;
        case 2:
            cin >> l >> r;

            for (int i = l - 1; i < r; i++)
                arr[i] = 0;

            break;
        }
    }

    return 0;
}
