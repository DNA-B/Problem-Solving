#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, taesu, P;
int arr[51];
int ans = 1, idx = -1;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> taesu >> P;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    sort(arr + 1, arr + N + 1, cmp);

    for (int i = 1; i <= N; i++)
    {
        if (arr[i] > taesu) // 나보다 큰 값 뒤에 들어가기
        {
            ans++;
            idx = i + 1;
        }
        else if (arr[i] == taesu) // 나랑 같은 값 뒤에 들어가기
        {
            idx = i + 1;
        }
    }

    if (idx > P) // 자리 꽉 차면 -1
        cout << -1;
    else
        cout << ans;

    return 0;
}