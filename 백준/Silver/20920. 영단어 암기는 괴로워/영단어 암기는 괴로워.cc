#include <bits/stdc++.h>

using namespace std;

map <string, int> dict;
int n, m;

bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second == b.second) // 출현빈도 같을 경우
    {
        if (a.first.length() == b.first.length()) // 길이도 같을 경우
            return a.first < b.first;
        else // 길이는 다를 경우
            return a.first.length() > b.first.length();
    }
    // default는 출현빈도가 더 많은 단어
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        
        if (str.length() < m) // m보다 짧은 단어는 그냥 외운다.
            continue;
        else // 아니면 counting
            dict[str]++;
    }

    vector <pair<string, int>> v(dict.begin(), dict.end()); // map정렬을 위해 vector로 변환
    sort(v.begin(), v.end(), compare);

    for (auto item : v)
        cout << item.first << "\n";

    return 0;
}