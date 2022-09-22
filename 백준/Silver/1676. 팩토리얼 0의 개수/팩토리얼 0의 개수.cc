#include <bits/stdc++.h>

using namespace std;

int main() // 5의 제곱수들로 나눈 몫이 0의 개수.
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int num_zero = 0;

    cin >> n;

    num_zero = (n / 5) + (n / 25) + (n / 125);

    cout << num_zero;

    return 0;
}