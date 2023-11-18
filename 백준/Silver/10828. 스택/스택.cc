#include <bits/stdc++.h>

using namespace std;

stack<int> st;
int N, x;
string order;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> order;

        if (order == "push")
        {
            cin >> x;
            st.push(x);
        }
        else if (order == "pop")
        {
            if (st.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (order == "size")
            cout << st.size() << "\n";
        else if (order == "empty")
            cout << st.empty() << "\n";
        else if (order == "top")
            cout << (st.empty() ? -1 : st.top()) << "\n";
    }

    return 0;
}