#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int in[4];
int out[4];
int sum[4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++)
        cin >> out[i] >> in[i];

    for (int i = 0; i < 4; i++) 
    {
        if (i == 0)
            sum[i] = in[i] - out[i];
        else
            sum[i] = sum[i - 1] + in[i] - out[i];  
    }

    sort(sum, sum + 4);
    cout << sum[3];

    return 0;
}