#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

double ans = 0;
double total_score = 0;
vector<tuple<string, double, string>> v;
map<string, double> m = {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0.0},
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 20; i++)
    {
        double score;
        string lecture, grade;

        cin >> lecture >> score >> grade;
        v.push_back({ lecture, score, grade });
    }

    for (auto item : v)
    {
        if (get<2>(item) == "P")
            continue;

        ans += (get<1>(item) * m[get<2>(item)]);
        total_score += get<1>(item);
    }

    cout << fixed;
    cout.precision(6);
    cout << ans / total_score;

    return 0;
}
