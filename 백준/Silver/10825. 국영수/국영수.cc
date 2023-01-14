#include <bits/stdc++.h>

using namespace std;

bool cmp(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b)
{

    if (get<1>(a) == get<1>(b))
    {
        if (get<2>(a) == get<2>(b))
        {
            if (get<3>(a) == get<3>(b))
            {
                return get<0>(a) < get<0>(b); // 이름 사전순
            }
            return get<3>(a) > get<3>(b); // 수학 내림차
        }
        return get<2>(a) < get<2>(b); // 영어 오름차
    }
    return get<1>(a) > get<1>(b); // 국어 내림차
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<tuple<string, int, int, int>> v;
    int n;
    string name;
    int korean, english, math;

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> name >> korean >> english >> math;
        v[i] = make_tuple( name, korean, english, math );
    }

    sort(v.begin(), v.end(), cmp);

    for (auto item : v)
        cout << get<0>(item) << "\n";

    return 0;
}