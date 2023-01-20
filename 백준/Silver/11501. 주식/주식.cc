#include <bits/stdc++.h>

using namespace std;

int x;
int t, n;
long long profit = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    
    while (t--)
    {
        stack<int> st;
        int cur;

        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            st.push(x);
        }
 
        cur = st.top();
        st.pop();

        while (!st.empty())
        {
            if (cur >= st.top())
            {
                profit += cur - st.top();
                st.pop();
            }
            else
            {
                cur = st.top();
                st.pop();
            }
        }
        
        if (profit <= 0)
            cout << 0 << "\n";
        else
            cout << profit << "\n";

        profit = 0;
    }

	return 0;
}