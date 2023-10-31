#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_GAP 500000

using namespace std;

int N;
int arr[101];

int get_gcd(int a, int b)
{
    return (b == 0 ? a : get_gcd(b, a % b));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 1; i < N; i++)
    {
        int gcd;

        gcd = get_gcd(arr[0], arr[i]);
        cout << arr[0] / gcd << "/" << arr[i] / gcd << "\n";
    }

    return 0;
}
