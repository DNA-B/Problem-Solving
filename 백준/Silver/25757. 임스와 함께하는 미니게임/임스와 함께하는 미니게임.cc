#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
char G;
set<string> name;
string tmp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> G;

    while (N--)
    {
        cin >> tmp;
        name.insert(tmp);
    }

    switch (G)
    {
    case 'Y': // 임스 제외 1명 필요
        cout << name.size();
        break;
    case 'F': // 임스 제외 2명 필요
        cout << name.size() / 2;
        break;
    case 'O': // 임스 제외 3명 필요
        cout << name.size() / 3;
        break;
    }

    return 0;
}