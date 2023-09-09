#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, B;
char arr[36];
string ans = "";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;

    for (int i = 10; i <= 35; i++)
        arr[i] = 'A' + (i - 10);

    while (N != 0)
    {
        int m;

        m = N % B;
        N /= B;

        if (m >= 10)
            ans = ans + arr[m];
        else
            ans = ans + to_string(m);
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
