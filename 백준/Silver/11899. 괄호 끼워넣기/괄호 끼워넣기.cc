#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

stack<char> st;
string str;
int ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
            continue;
        }
        else if (str[i] == ')')
        {
            if (st.empty() || st.top() != '(')
                ans++;

            if (!st.empty())
                st.pop();
        }
    }

    ans += st.size();
    cout << ans;

    return 0;
}
