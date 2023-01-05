#include <bits/stdc++.h>

using namespace std;

/*
BOJ 1448 : 삼각형 만들기
- 정렬을 한 후
- 연속된 3개의 수가 삼각형이 안된다면 연속되지 않는 나머지도 삼각형을 이룰 수 없다.
- 1 2 3 4 5 9 라면 4 5 9가 삼각형이 안 될 경우 3 4 9도 안되기 때문
- 그러므로 3개씩 묶어서 삼각형을 이루는 경우를 찾고 최댓값을 갱신한다.
*/

vector <int> v(100001);
int n;
int res = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    for (int i = v.size() - 1; i > 1; i--)
    { 
        if (v[i] < v[i - 1] + v[i - 2])
        {
            if (res < v[i] + v[i - 1] + v[i - 2])
                res = v[i] + v[i - 1] + v[i - 2];
        }
    }

    if (res == -1)
        cout << -1;
    else
        cout << res;

    return 0;
}