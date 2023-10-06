#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;

int GCD(int a, int b)
{
    if (b != 0)
        return GCD(b, a % b);
    else
        return a;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        long long a, b;

        cin >> a >> b;
        cout << (a * b) / GCD(a, b) << "\n";
    }
    return 0;
}
