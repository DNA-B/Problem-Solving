#include<bits/stdc++.h>

using namespace std;

int alp[27];
int N;
int L = 0, O = 0, V = 0, E = 0;
string y_name, tmp;
vector<pair<string, int>> v;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> y_name;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        fill(alp, alp + 27, 0);

        cin >> tmp;
        v.push_back({ tmp, 0 });

        for (int j = 0; j < y_name.length(); j++)
            alp[y_name[j] - 'A'] += 1;

        for (int j = 0; j < v[i].first.length(); j++)
            alp[v[i].first[j] - 'A'] += 1;

        L = alp[11];
        O = alp[14];
        V = alp[21];
        E = alp[4];
        v[i].second = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
    }

    //abcdE fghij kLmnO pqrst uV
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first;
    
    return 0;
}