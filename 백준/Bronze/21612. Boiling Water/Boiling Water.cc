#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int calc(int b)
{
    return (5 * b) - 400;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int B;
    int C;

    cin >> B;

    C = calc(B);

    cout << C << "\n";
    
    if (C == 100)
        cout << 0;
    else if (C < 100)
        cout << 1;
    else
        cout << -1;

    return 0;
}