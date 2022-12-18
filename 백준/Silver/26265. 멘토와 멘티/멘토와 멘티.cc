#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<string, string>> mento_menti(100001);

bool compare(const pair<string, string>& a, const pair<string, string>& b)
{
    if (a.first == b.first) // 멘토 같으면
        return a.second > b.second; // 멘티 역순
    else // default = 오름차순
        return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    mento_menti.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mento_menti[i].first >> mento_menti[i].second;
    }

    sort(mento_menti.begin(), mento_menti.end(), compare);

    for (auto item : mento_menti)
    {
        cout << item.first << " " << item.second << "\n";
    }

    return 0;
}