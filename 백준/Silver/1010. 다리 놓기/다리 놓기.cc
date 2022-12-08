#include <bits/stdc++.h>

using namespace std;

int mem[31][31];

void make_bridge(int n, int r) 
{
	// nCr = (n-1)C(r-1) + (n-1)C(r)
	for (int i = 0; i <= n; i++) 
	{
		for (int j = 0; j <= r; j++) 
		{
			if (i == j || j == 0)
				mem[i][j] = 1;
			else
				mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int tc;
	int n, m;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> n >> m;

		make_bridge(m, n);
		cout << mem[m][n] << "\n";
	}

    return 0;
}