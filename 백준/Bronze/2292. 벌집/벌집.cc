#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    long long cur = 1, idx = 1;
    int res = 1;

    cin >> n;

    while (cur < n)
    {
        // 각 layer의 최댓값이 6의 배수를 더한 값만큼 증가하고 있다.
        // 그 경계를 기준으로 layer를 나눠서 개수를 구한다.
        cur += 6 * idx;
        idx++;
        res++;
    }

    cout << res;

    return 0;
}