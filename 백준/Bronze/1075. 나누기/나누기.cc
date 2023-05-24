#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, F;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> F;

    N /= 100;
    N *= 100;

    while (N % F != 0) 
        N++;

    N %= 100;

    if (N < 10) 
        cout << "0" << N << endl;
    else 
        cout << N << endl;

    return 0;
}