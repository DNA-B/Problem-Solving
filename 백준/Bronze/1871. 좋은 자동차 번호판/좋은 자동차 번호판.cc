#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, a;
int sum1 = 0, sum2 = 0, cnt = 0;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        sum1 = (str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + (str[2] - 'A');
        sum2 = (str[4] - 48) * 1000 + (str[5] - 48) * 100 + (str[6] - 48) * 10 + (str[7] - 48);

        if (abs(sum1 - sum2) <= 100)
            cout << "nice\n";
        else
            cout << "not nice\n";
    }

    return 0;
}