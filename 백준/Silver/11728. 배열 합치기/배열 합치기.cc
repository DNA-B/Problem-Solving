#include <bits/stdc++.h>

using namespace std;

/*
BOJ 11728 : 배열 합치기
- merge sort의 투 포인터 방식을 이용한 풀이
*/

vector <int> v1(1000001);
vector <int> v2(1000001);
int n, m, p1, p2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    p1 = 0;
    p2 = 0;

    while (p1 < n && p2 < m) // 둘 중 하나가 끝까지 가면 반복 종료
    {
        if (v1[p1] < v2[p2])
        {
            cout << v1[p1] << " ";
            p1++;
        }
        else
        {
            cout << v2[p2] << " ";
            p2++;
        }
    }

    if (p1 == n) // v1 배열이 먼저 끝났다면 v2 나머지 출력
    {
        while (p2 < m)
        {
            cout << v2[p2] << " ";
            p2++;
        }
    }
    else // v2 배열이 먼저 끝났다면 v1 나머지 출력
    {
        while (p1 < n)
        {
            cout << v1[p1] << " ";
            p1++;
        }
    }

    return 0;
}