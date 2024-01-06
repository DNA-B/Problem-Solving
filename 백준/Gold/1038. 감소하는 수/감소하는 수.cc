#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> ans;
string s;

void solve()
{
	for (int i = 0; i < s[s.length() - 1] - '0'; i++) // 문자열의 맨 끝 수보다 작은 범위를 탐색하여 시간 절약
	{
		s.push_back(i + '0');
		ans.push_back(stoll(s));
		solve();
		s.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		s.push_back(i + '0');
		ans.push_back(stoll(s));
		solve();
		s.pop_back();
	}

	sort(ans.begin(), ans.end()); // 순서 맞춰주기

	if (N >= ans.size()) // MAX값인 9876543210이 1022번째 수, ans.size()는 1023이므로 이보다 큰 경우에 감소하는 수가 존재하지 않는다.
		cout << -1 << "\n";
	else
		cout << ans[N] << "\n";

	return 0;
}