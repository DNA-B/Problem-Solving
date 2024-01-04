#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, X, Y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;

		if (X < Y)
			cout << "NO BRAINS\n";
		else
			cout << "MMM BRAINS\n";
	}


	return 0;
}