#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n, tmp1, tmp2;
    int cycle = 0;
    int sum = 0;

    cin >> n;

    if (n.length() < 2)
        n += '0';

    tmp1 = n;

    do // 일단 한 번은 무조건 수행
    {
        for (int i = 0; i < tmp1.length(); i++) // 합
            sum += tmp1[i] - '0';

        tmp2 = tmp1[tmp1.length() - 1]; // 원래 수의 맨 끝
        tmp2 += to_string(sum)[to_string(sum).length() - 1]; // 합의 맨 끝

        cycle++;
        sum = 0;
        tmp1 = tmp2;

    } while (tmp1 != n);

    cout << cycle;

    return 0;
}