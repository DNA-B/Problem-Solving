#define _CRT_SECURE_NO_WARNINGS
#define BOUND 1000
#define MAX_VALUE 1000000
#define first X
#define second Y

#include <bits/stdc++.h>

using namespace std;

int N;
int house[BOUND + 5][3];
int ans = INT_MAX;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> house[i][j];

	for (int first = 0; first < 3; first++) { // first는 첫 번째 집의 색을 뜻함 {R, G, B}
		int mem[BOUND + 5][3];

		for (int i = 0; i < 3; i++) { // 선택한 색의 mem을 제외한 나머지는 MAX_VALUE로 초기화하여 선택 못하게 막음
			if (i == first) // 현재 
				mem[1][first] = house[1][first];
			else
				mem[1][i] = MAX_VALUE;
		}

		for (int i = 2; i <= N; i++) {
			mem[i][0] = min(mem[i - 1][1], mem[i - 1][2]) + house[i][0];
			mem[i][1] = min(mem[i - 1][0], mem[i - 1][2]) + house[i][1];
			mem[i][2] = min(mem[i - 1][0], mem[i - 1][1]) + house[i][2];
		}

		for (int i = 0; i < 3; i++) { // 첫 번째 집과 다른 색 중에서 ans 갱신
			if (i != first)
				ans = min(ans, mem[N][i]);
		}
	}

	cout << ans;

	return 0;
}