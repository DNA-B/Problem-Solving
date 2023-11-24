#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int path_i, path_j;
int mem[1001][1001];
stack<char>st;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                mem[i][j] = mem[i - 1][j - 1] + 1;
            else
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
        }
    }

    path_i = s1.size();
    path_j = s2.size();

    cout << mem[path_i][path_j] << "\n";

    if (mem[path_i][path_j] != 0)
    {
        while (mem[path_i][path_j] != 0)
        {
            if (mem[path_i][path_j] == mem[path_i - 1][path_j])
                path_i--;
            else if (mem[path_i][path_j] == mem[path_i][path_j - 1])
                path_j--;
            else
            {
                st.push(s1[path_i - 1]); // 1-base range이므로 index - 1값으로 문자 추출
                path_i--;
                path_j--;
            }
        }

        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
    }

    return 0;
}
