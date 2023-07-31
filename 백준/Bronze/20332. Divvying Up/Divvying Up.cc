#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int sum_prize;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        int x;

        cin >> x;

        sum_prize += x;
    }

    cout << (sum_prize % 3 == 0 ? "yes" : "no");

    return 0;
}
