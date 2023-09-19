#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, X, L;
string tmp_X;
string min_grade = "";
int min_v = INF;
map<string, int> m = {
    {"A+", 450},
    {"A0", 400},
    {"B+", 350},
    {"B0", 300},
    {"C+", 250},
    {"D+", 150},
    {"C0", 200},
    {"D0", 100},
    { "F", 0 } };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> tmp_X;

    X = (stoi(tmp_X.substr(0, 1)) * 100) + stoi(tmp_X.substr(2, 2));

    int cur_score = 0;
    int cnt = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int c;
        string g;

        cin >> c >> g;

        cur_score += c * m[g];
        cnt += c;
    }

    cin >> L;

    cnt += L;
    for (auto item : m)
    {
        int tmp = (cur_score + (item.second * L)) / cnt;

        if (tmp > X && tmp < min_v)
        {
            min_v = tmp;
            min_grade = item.first;
        }
    }

    if (min_v == INF)
        cout << "impossible";
    else
        cout << min_grade;

    return 0;
}
