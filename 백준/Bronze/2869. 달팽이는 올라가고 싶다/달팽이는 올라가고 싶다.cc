#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, v;
    long long res;
    long long day_height;

    cin >> a >> b >> v;
    day_height = a - b;

    if ((v - a) % (a - b) == 0) // a - b는 미끄러진 것 포함이므로 v에서 미리 a를 뺀 값으로 계산(res + 1)
        res = (v - a) / (a - b) ;
    else
        res = (v - a) / (a - b) + 1;

    cout << res + 1;

    return 0;
}