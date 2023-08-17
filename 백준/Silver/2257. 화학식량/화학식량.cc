#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string fomula;
int ans = 0;
stack<int> st;
map<char, int> m = 
{
    {'H', 1},
    {'C', 12},
    {'O', 16}
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> fomula;

    for (int i = 0; i < fomula.length(); i++)
    {
        if (fomula[i] >= '2' && fomula[i] <= '9')
        {
            int tmp = st.top();

            st.pop();
            st.push(tmp * (fomula[i] - '0'));
        }
        else if (fomula[i] == ')')
        {
            int tmp = 0;
            while (char(st.top()) != '(')
            {
                tmp += st.top();
                st.pop();
            }

            st.pop();
            st.push(tmp);
        }
        else
        {
            if (fomula[i] == '(')
                st.push(fomula[i]);
            else
                st.push(m[fomula[i]]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans;

    return 0;
}