#include <bits/stdc++.h>

using namespace std;

long long mem[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    int n;

    cin >> n;
    
    mem[0] = 0;
    mem[1] = 1;

    for (int i = 2; i <= n; i++)
        mem[i] = mem[i - 2] + mem[i - 1];
    
    cout << mem[n];

	return 0;
}