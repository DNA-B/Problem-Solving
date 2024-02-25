#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans = 0;
vector<int> parent(100001);

int find_parent(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a == b)
		return;

	parent[max(a, b)] = min(a, b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0, st, en; i < M; i++)
	{
		cin >> st >> en;

		if (find_parent(st) != find_parent(en)) // 부모가 다르면 union -> 그래프 생성
			union_parent(st, en);
		else
			ans++; // 부모가 같은 경우 -> (1, 2) -> (1, 3) -> (2, 3)이라면 사이클이 발생한다. -> 제거 작업
	}

	for (int i = 1; i <= N; i++) // 부모가 자기 자신인 경우 -> 그래프가 형성되지 않았다 -> 합치는 작업
	{
		if (find_parent(i) == i)
			ans++;
	}

	cout << ans - 1; // 바로 위의 반복문에서 root에서도 ans++되므로 1 빼주어야 한다.

	return 0;
}