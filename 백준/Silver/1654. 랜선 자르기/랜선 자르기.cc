#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define BOUND 0.15

using namespace std;

int K, N;
int arr[10005];

bool check(long long x)
{
    long long cur = 0;

    for (int i = 0; i < K; i++)
        cur += arr[i] / x;

    return cur >= N;
}

long long binary_search()
{
    long long st = 1;
    long long en = pow(2, 31) - 1;

    while (st < en)
    {
        long long mid = (st + en + 1) / 2;

        if (check(mid))
            st = mid;
        else
            en = mid - 1;
    }

    return st;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;

    for (int i = 0; i < K; i++)
        cin >> arr[i];

    cout << binary_search();

    return 0;
}
