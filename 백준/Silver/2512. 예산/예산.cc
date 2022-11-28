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

    cin >> n;
    v.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cin >> m;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }

    if(sum<=m) // 배정이 되면
        cout << *max_element(v.begin(), v.end());
    else // 배정이 안된다면(이분 탐색)
    {
        long long low = 0;
        long long high = 100000;
        long long mid;
        
        while (low + 1 < high)
        {
            mid = (low + high) / 2;
            sum = 0;

            for (int i = 0; i < n; i++)
            {
                if (v[i] > mid)
                    sum += mid;
                else
                    sum += v[i];
            }

            if (sum > m)
                high = mid;
            else
                low = mid;
        }

        cout << low;
    }
    
    return 0;
}