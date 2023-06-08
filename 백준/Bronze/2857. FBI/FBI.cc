#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

string fbi[6];
vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 5; i++)
    {
        cin >> fbi[i];

        if (fbi[i].find("FBI") == string::npos)
            continue;
        else
            ans.push_back(i);
    }

    if (ans.size() == 0)
        cout << "HE GOT AWAY!" << '\n';
    else
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }

    return 0;
}