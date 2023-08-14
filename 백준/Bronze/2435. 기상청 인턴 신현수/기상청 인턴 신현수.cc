#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PI 3.1415927

using namespace std;

int N, K;
int arr[101];
int sequence[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(sequence, sequence + 101, -INF);
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    
    for (int i = 0; i < N - (K - 1); i++)
    {
        int total = 0;
 
        for (int j = 0; j < K; j++)
            total += arr[i + j];

        sequence[i] = total;
    }

    cout << *max_element(sequence, sequence + (N - (K - 1)));

    return 0;
}
