#include <bits/stdc++.h>

using namespace std;

int N, x;

struct cmp 
{
    bool operator()(int x, int y)
    {
        if (abs(x) == abs(y)) // 같으면 실제로 작은 값
            return x > y;
        else
            return abs(x) > abs(y);     
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, cmp> pq;

    cin >> N;
    
    while (N--)
    {
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }

            cout << pq.top() << "\n";
            pq.pop();
            continue;
        }

        pq.push(x);  
    }

    return 0;
}