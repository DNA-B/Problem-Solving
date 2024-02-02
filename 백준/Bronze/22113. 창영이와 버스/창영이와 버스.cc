#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[101][101], chang[101];
int price = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> chang[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	for (int i = 1; i < M; i++)
		price += A[chang[i - 1]][chang[i]];

	cout << price;

	return 0;
}