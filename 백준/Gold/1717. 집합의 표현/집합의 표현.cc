#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parent(1000001);

int getParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

void findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if (a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int union_find;
    int a, b;

    cin >> n >> m;

    parent.resize(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;
 
    while (m--)
    {
        cin >> union_find >> a >> b;

        if (union_find == 0)
            unionParent(a, b);
        else
            findParent(a, b);
    }

    return 0;
}