#include <bits/stdc++.h>

using namespace std;

map <char, pair<char, char>> tree;

void pre(char node) // 전위 [p, l, r]
{
    cout << node;

    if (tree[node].first != '.') // 왼쪽 자식 있으면 
        pre(tree[node].first);

    if (tree[node].second != '.') // 오른쪽 자식 있으면 
        pre(tree[node].second);
}

void in(char node) // 중위 [l, p, r]
{
    if (tree[node].first != '.') // 왼쪽 자식 있으면 
        in(tree[node].first);

    cout << node;

    if (tree[node].second != '.') // 오른쪽 자식 있으면 
        in(tree[node].second);
}

void post(char node) // 후위 [l, r, p]
{
    if (tree[node].first != '.') // 왼쪽 자식 있으면 
        post(tree[node].first);

    if (tree[node].second != '.') // 오른쪽 자식 있으면 
        post(tree[node].second);
    cout << node;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int node_n = 0;
    char p, l, r;
    cin >> node_n;

    for (int i = 0; i < node_n; i++)
    {
        cin >> p >> l >> r;
        tree[p] = { l,r };
    }

    pre('A');
    cout << "\n";
    in('A');
    cout << "\n";
    post('A');

    return 0;
}