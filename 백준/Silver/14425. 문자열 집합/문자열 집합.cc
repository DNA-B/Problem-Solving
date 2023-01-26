#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<string> s;
    int n, m;
    int answer = 0;
    string str;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        s.insert(str);
    }
        
    for (int i = 0; i < m; i++)
    {
        cin >> str;

        if (s.find(str) != s.end())
            answer++;
    }

    cout << answer;

	return 0;
}