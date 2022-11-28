#include <bits/stdc++.h>

using namespace std;


/*
- 2512번 : 예산
- 조건1은 그냥 v의 최댓값 뽑아서 구현
- 조건2를 만족해야하는 경우 -> 이분탐색
- 모든 요구 예산이 m보다 작은데 그 중 최대가 되는 값을 찾는다.
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