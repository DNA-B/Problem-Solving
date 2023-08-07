#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int A, B, C;
int N;
int arr[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    cin >> N;

    int a, b, c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a >> b >> c;
            arr[i] += (a * A) + (b * B) + (c * C);
        }
    }

    cout << *max_element(arr, arr + N);

    return 0;
}
