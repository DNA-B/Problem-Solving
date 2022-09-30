#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
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
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(n);
        }
    }

    return 0;
}