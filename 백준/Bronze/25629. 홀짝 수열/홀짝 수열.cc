#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int even, odd;
int arr[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    if (even == (N / 2) && odd == ((N / 2) + (N % 2)))
        cout << 1;
    else
        cout << 0;

    return 0;
}