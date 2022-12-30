#include <bits/stdc++.h>

using namespace std;

/*
BOJ 2170 : 선 긋기
- 라인 스위핑 기본 문제
- 선 들을 정렬한 후에 이것들이 이어지는지 아닌지에 따른 분류
- 포함되는 경우도 함께 처리하도록 고려
*/

vector <pair<int, int>> line(1000001);
int n;
int x, y;
long long res = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    line.resize(n);

    for (int i = 0; i < n; i++)
        cin >> line[i].first >> line[i].second;

    sort(line.begin(), line.end());
    
    x = line[0].first;
    y = line[0].second;

    for (int i = 1; i < n; i++)
    {
        if (line[i].first <= y) // '<='를 통해 포함되는 경우 처리
            y = max(line[i].second, y);
        else // 포함되지 않는다면 지금까지 이어진 선 길이를 더한 후 선 변경
        {
            res += y - x;
            x = line[i].first;
            y = line[i].second;
        }
    }

    res += y - x; // 마지막 선까지 더해주고 결과 출력
    cout << res;

    return 0;
}