#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
stack<int> st;

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
            st.push(x);
            break;
        case 2:
            if (st.empty())
                cout << -1 << "\n";
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
            break;
        case 3:
            cout << st.size() << '\n';
            break;
        case 4:
            if (st.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            break;
        case 5:
            if (st.empty())
                cout << -1 << "\n";
            else
                cout << st.top() << "\n";
            break;
        }
    }

    return 0;
}
