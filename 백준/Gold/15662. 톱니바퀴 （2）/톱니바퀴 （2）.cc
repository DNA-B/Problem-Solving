#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int T, K, N, R;
int gear[1005][8];
bool is_rotate[1005];
//=========================//

// n : 톱니, r : 방향
void gear_rotate(int n, int r) {
	if (n < 1 || n > T)
		return;

	is_rotate[n] = true; // 이 톱니는 rotate 했다는 것을 표시

	if (n == 1) {// 오른쪽만 비교
		if (is_rotate[n + 1] == false) { // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
			if (gear[n][2] != gear[n + 1][6]) // n은 [2], 오른쪽은 [6]번 인덱스 주의
				gear_rotate(n + 1, -r);
		}
	}
	else if (n == T) {// 왼쪽만 비교

		if (is_rotate[n - 1] == false) { // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
			if (gear[n][6] != gear[n - 1][2]) // n은 [6], 왼쪽은 [2]번 인덱스 주의
				gear_rotate(n - 1, -r);
		}
	}
	else { // 양쪽 확인 
		if (is_rotate[n + 1] == false) { // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
			if (gear[n][2] != gear[n + 1][6]) // n은 [2], 오른쪽은 [6]번 인덱스 주의
				gear_rotate(n + 1, -r);
		}

		if (is_rotate[n - 1] == false) { // 옆 바퀴가 돌아간 적이 없고, 극이 다르다면
			if (gear[n][6] != gear[n - 1][2]) // n은 [6], 왼쪽은 [2]번 인덱스 주의
				gear_rotate(n - 1, -r);
		}
	}

	if (r == 1) // 시계
		rotate(gear[n], gear[n] + 8 - r, gear[n] + 8);
	else if (r == -1) // 반시계
		rotate(gear[n], gear[n] - r, gear[n] + 8);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	char input;
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> input; // [N : 0] <--> [S : 1]
			gear[i][j] = input - '0';
		}
	}

	cin >> K;

	while (K--) {
		cin >> N >> R;
		fill(is_rotate + 1, is_rotate + T + 1, false);
		gear_rotate(N, R);
	}

	int cnt = 0;
	for (int i = 1; i <= T; i++)
		cnt += gear[i][0];

	cout << cnt;
}