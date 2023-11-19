#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << ((N % 2 == 0) ? "Duck" : "Goose");

    return 0;
}
