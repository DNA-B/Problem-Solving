#include <bits/stdc++.h>

using namespace std;

/*
BOJ 1931 : 회의실 배정
- 스케쥴링 기본 문제
- 마감시간이 가장 빠른 순으로 정렬
- 해당 문제는 끝남과 동시에 시작 가능
*/

vector <pair<int, int>> meeting(100001);
int n;
long long x, y;
int res = 0;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) // 같은 경우 시작 시간이 더 작은 회의가 최적
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    meeting.resize(n);

    for (int i = 0; i < n; i++)
        cin >> meeting[i].first >> meeting[i].second;

    sort(meeting.begin(), meeting.end(), compare);
    
    x = meeting[0].first;
    y = meeting[0].second;
    res++;

    for (int i = 1; i < n; i++)
    {
        if (meeting[i].first >= y) // 다음 회의 시작 시간이 현재 회의 끝 시간보다 '>=' 라면 (끝 시간 포함)
        {
            res++;
            x = meeting[i].first;
            y = meeting[i].second;
        }
    }

    cout << res;

    return 0;
}