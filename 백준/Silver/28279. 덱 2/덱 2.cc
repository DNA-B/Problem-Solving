#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        int order;
        int x;

        cin >> order;

        switch (order)
        {
        case 1:
            cin >> x;

            dq.push_front(x);
            break;
        case 2:
            cin >> x;

            dq.push_back(x);
            break;
        case 3:
            if (!dq.empty())
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else
                cout << -1 << "\n";
            break;
        case 4:
            if (!dq.empty())
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else
                cout << -1 << "\n";
            break;
        case 5:
            cout << dq.size() << "\n";
            break;
        case 6:
            if (dq.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            break;
        case 7:
            if (!dq.empty())
                cout << dq.front() << "\n";
            else
                cout << -1 << "\n";
            break;
        case 8:
            if (!dq.empty())
                cout << dq.back() << "\n";
            else
                cout << -1 << "\n";
            break;
        }
    }

    return 0;
}
