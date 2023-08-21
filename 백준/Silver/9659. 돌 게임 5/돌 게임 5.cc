#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

long long N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
       
    cin >> N;

    if (N % 2 == 0)
        cout << "CY";
    else
        cout << "SK";

    return 0;
}