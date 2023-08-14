#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PI 3.1415927

using namespace std;

// 바퀴의 지름을 안다면 회전수를 통해 이동거리 측정 가능
// 바퀴가 회전하는 동안 걸린 시간을 안다면 평균 속도 측정 가능
// 지름, 회전수, 걸린 시간 -> 총 이동 거리와 평균 속도 계산

int N = 0;
double diameter, cycle, t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> diameter >> cycle >> t;

        if (cycle == 0)
            return 0;

        N++;
  
        t /= 3600.0;
        double distance = (diameter * PI) * cycle  / 63360.0;
        double mph = distance / t;

        cout << fixed;
        cout.precision(2);
        cout << "Trip #" << N << ": " << distance << " " << mph << "\n";
    }

    return 0;
}
