#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, S, M;
int arr[51];
bool is_possible[51][1001]; // [N][M] -> N번째 곡에서 M번 음량으로 연주 가능 
int ans = -1;

void solve(int idx, int vol)
{
	if (idx > N)
		return;
	if (is_possible[idx][vol])
		return;

	is_possible[idx][vol] = true;

	if (vol - arr[idx] >= 0) // 0보다 작을 수 없음
		solve(idx + 1, vol - arr[idx]);
	if (vol + arr[idx] <= M) // M보다 클 수 없음
		solve(idx + 1, vol + arr[idx]);

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solve(0, S);

	for (int i = 0; i <= M; i++)
	{
		if (is_possible[N][i])
			ans = i;
	}

	cout << (ans == -1 ? -1 : ans);

	return 0;
}