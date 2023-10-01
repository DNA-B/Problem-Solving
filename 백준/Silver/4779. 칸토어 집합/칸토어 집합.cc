#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
string s;

void cantor(int cur, int len)
{
    if (len == 0)
        return;

    for (int i = cur; i < cur + len; i++)
        s[i] = ' ';

    cantor((cur - len) + (len / 3), len / 3);
    cantor((cur + len) + (len / 3), len / 3);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        s = "";

        cin >> N;

        if (cin.eof())
            break;

        int len = pow(3, N);
        for (int i = 0; i < len; i++)
            s += "-";

        cantor(len / 3, len / 3);

        cout << s << "\n";
    }

    return 0;
}
