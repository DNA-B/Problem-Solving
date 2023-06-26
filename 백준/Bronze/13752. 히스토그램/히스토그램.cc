#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> k;

        while (k--)
            cout << '=';
        cout << "\n";
    }

    return 0;
}