#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 절댓값 기준 오름차순 정렬 하기 위해 greater, 또한 원래 값을 보존하기 위해 pair사용
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int rep;
    long long n;

    cin >> rep;

    while (rep--)
    {
        cin >> n;
     
        if (n == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push({ abs(n), n });
        }
    }

    return 0;
}