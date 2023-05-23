#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, a, b;
int tmp = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) 
    {
        cin >> a >> b;

        tmp = a;
        b = b % 4 + 4;

        for (int i = 2; i <= b; i++) 
            tmp = tmp * a % 10;

        if (tmp == 0)
            tmp = 10;

        cout << tmp << "\n";
    }

    return 0;
}