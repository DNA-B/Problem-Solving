#include <bits/stdc++.h>

using namespace std;

int N, K;
int W[101];
int V[101];
int mem[101][100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{

			if (j - W[i] >= 0) 
				mem[i][j] = max(mem[i - 1][j], mem[i - 1][j - W[i]] + V[i]);
			else
				mem[i][j] = mem[i - 1][j];
		}
	}

	cout << mem[N][K];

    return 0;
}