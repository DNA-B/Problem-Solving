#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

set<int> s;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (int item : s)
        cout << item << " ";

    return 0;
}