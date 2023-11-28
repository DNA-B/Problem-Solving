#include <bits/stdc++.h>

using namespace std;

int T;
int x_1, x_2, y_1, y_2, r_1, r_2;
double d, pow_plus, pow_minus; // 실수 연산 피하기 위해 제곱으로 취급

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

        d = pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2);
        pow_plus = pow(r_1 + r_2, 2);
        pow_minus = pow(r_1 - r_2, 2);

        if (d == 0) // 두 원이 겹치는 경우
            cout << (r_1 == r_2 ? -1 : 0) << "\n";
        else if (pow_minus < d && d < pow_plus) // (r - r')^2 < d < (r + r')^2
            cout << 2 << "\n";
        else if (d < pow_minus || d > pow_plus) // 겹치지 않는 경우
            cout << 0 << "\n";
        else if (pow_minus == d || pow_plus == d) // (r - r')^2 = d OR (r + r')^2 = d
            cout << 1 << "\n";
    }

    return 0;
}
