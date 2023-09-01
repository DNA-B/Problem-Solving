#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = N; i > 0; i--)
    {
        v.insert(v.begin(), i);
        for (int j = 0; j < i; j++)
            rotate(v.begin(), v.end() - 1, v.end());
    }

    for (auto item : v)
        cout << item << " ";

    return 0;
}