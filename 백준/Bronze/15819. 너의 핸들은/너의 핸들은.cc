#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, I;
string handle[102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> I;

    for (int i = 0; i < N; i++)
        cin >> handle[i];

    sort(handle, handle + N);

    cout << handle[I - 1];

    return 0;
}