#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int triangle[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
        cin >> triangle[i];

    sort(triangle, triangle + 3);

    // 세 변의 길이를 줬을 때 길이가 가장 긴 변의 길이는 다른 두 변 길이의 합보다 작아야 한다.
    if (triangle[2] >= (triangle[0] + triangle[1]))
        cout << triangle[0] + triangle[1] + (triangle[0] + triangle[1] - 1); // 만약 작지 않다면 나머지 (두 변의 길이의 합 - 1)로 길이를 변경한다.
    else
        cout << triangle[0] + triangle[1] + triangle[2];

    return 0;
}
