#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    long long a, b, v, res;
    cin >> a >> b >> v;

    // a - b는 미끄러진 것 포함이므로 v에서 미리 a를 뺀 값으로 계산(res + 1)
    res = (v - a) % (a - b) == 0 ? (v - a) / (a - b) : (v - a) / (a - b) + 1;
    cout << res + 1;

    return 0;
}