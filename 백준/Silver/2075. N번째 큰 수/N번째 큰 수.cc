#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        cin >> x;
        
        if (pq.size() > n) // 만약 n이 5이면 5일 때마다 최소값 pop후에 push
            pq.pop();

        pq.push(x);
    }

    pq.pop();
    cout << pq.top(); // 입력이 끝나고 나면 pq의 top은 n번째로 큰값이 들어가 있다.

    return 0;
}