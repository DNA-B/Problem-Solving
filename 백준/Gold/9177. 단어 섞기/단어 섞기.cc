#include<bits/stdc++.h>

using namespace std;

int N;
string str1, str2, con_str;
int str1_len, str2_len, con_str_len;
int one, two, three;
bool vis[201][201];
queue <tuple<int, int, int>> q;

int bfs()
{
    while (!q.empty())
    {
        tie(one, two, three) = q.front();
        q.pop();


        if (three == con_str.length())
            return 1;

        if (vis[one + 1][two] == 0 && str1[one] == con_str[three])
        {
            vis[one + 1][two] = 1;
            q.push({ one + 1, two, three + 1 });
        }

        if (vis[one][two + 1] == 0 && str2[two] == con_str[three])
        {
            vis[one][two + 1] = 1;
            q.push({ one, two + 1, three + 1 });
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        q = queue<tuple<int, int, int>>();
        for (int i = 0; i < 201; i++)
            fill(vis[i], vis[i] + 201, 0);

        cin >> str1 >> str2 >> con_str;
        
        str1_len = str1.length();
        str2_len = str2.length();
        con_str_len = con_str.length();

        q.push({ 0, 0, 0});
        vis[0][0] = 1;

        if(bfs() == 1)
            cout << "Data set " << i << ": yes\n";
        else
            cout << "Data set " << i << ": no\n";
    }

    return 0;
}