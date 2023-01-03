#include <bits/stdc++.h>

using namespace std;

int mem[20001];

void self_number(int n)
{
    if (n > 10000)
        return;

    int tmp1;
    string tmp2;

    tmp1 = n;
    tmp2 = to_string(tmp1);
    
    for (int i = 0; i < tmp2.length(); i++)
        tmp1 += tmp2[i] - '0';

    mem[tmp1]++;

    self_number(n + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    self_number(1);

    for (int i = 1; i < 10001; i++)
    {
        if (mem[i] == 0)
            cout << i << "\n";
    }

    return 0;
}