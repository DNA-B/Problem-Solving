#include <bits/stdc++.h>

using namespace std;

int N, M;
int P, L;
int mileage[101];
int min_mile[101];
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> P >> L;

        for (int j = 0; j < P; j++)
            cin >> mileage[j];

        sort(mileage, mileage + P);

        if (L > P) // 수강인원이 더 많으면 마일리지를 1만 넣어도 가능
            min_mile[i] = 1;
        else // 그게 아니면 L == P인 지점에서 같은 마일리지를 넣으면 된다.
            min_mile[i] = mileage[P - L];
    }

    sort(min_mile, min_mile + N); // 각 과목마다 필요한 마일리지 오름차순 정렬

    for (int i = 0; i < N; i++)
    {
        if (min_mile[i] <= M)
        {
            ans++;
            M -= min_mile[i];
        }
        else
        {
            break;
        }
    }

    cout << ans;

    return 0;
}