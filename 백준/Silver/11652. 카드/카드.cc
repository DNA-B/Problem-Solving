#include <bits/stdc++.h>

using namespace std;

map<long long, int> m;
int n;

bool compare(const pair<long long, int>& a, const pair<long long, int>& b)
{
    if (a.second == b.second) // 개수 같으면 first 작은 순으로
        return a.first < b.first;

    return a.second > b.second; // default : 개수 많은 순
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
    }

    vector<pair<long long, int>> v(m.begin(), m.end()); // map을 compare로 정렬하기 위해서 vector로 변환
    sort(v.begin(), v.end(), compare);

    cout << v[0].first;

    return 0;
}