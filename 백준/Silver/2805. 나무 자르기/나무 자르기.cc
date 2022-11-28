#include <bits/stdc++.h>

using namespace std;


/*
- 2805번 : 나무 자르기
- 높이의 클수록 가져가는 나무 양이 줄어든다.
- 즉 최대한 M에 비슷한 값을 가지게 하는 높이를 설정
- 이것을 이분탐색을 사용하여 O(logN)의 시간복잡도로 처리
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    long long sum = 0;
    vector<long long> v;

    cin >> n >> m;
    v.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long low = 0;
    long long high = 1000000000;
    long long mid = (low + high) / 2;

    while (low + 1 < high)
    {
        mid = (low + high) / 2;
        sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i] > mid)
                sum += v[i] - mid;
        }

        if (sum >= m)
            low = mid;
        else
            high = mid;
    }

    cout << low;

    return 0;
}