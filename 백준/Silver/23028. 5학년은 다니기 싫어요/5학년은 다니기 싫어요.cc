#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

/*
총 130학점 이상
그중 66학점은 전공
N학기를 마쳤고 // 전공학점은 A // 총 학점은 B
한 과목에 3학점 // 최대 6과목 가능 -> 18학점
*/

int N, A, B, X, Y;
int major, total, left_lec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A >> B;

    major = A;
    total = B;

    while (true)
    {
        if (N >= 8)
            break;

        cin >> X >> Y;

        major += (3 * X);
        left_lec = 6 - X;

        if (left_lec >= Y)
            total += (3 * X) + (3 * Y);
        else
            total += (3 * X) + (3 * left_lec);

        N++;
    }

    if (major >= 66 && total >= 130)
        cout << "Nice";
    else
        cout << "Nae ga wae";

    return 0;
}
