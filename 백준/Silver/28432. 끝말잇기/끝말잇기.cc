#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int N, M;
string words[105];
unordered_map<string, bool> dict;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int question_idx = -1;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		if (words[i] == "?")
			question_idx = i;
		else
			dict[words[i]] = true;
	}

	cin >> M;

	string A;
	while (M--) {
		cin >> A;

		if (dict[A]) // 1. 중복 단어
			continue;

		if (question_idx > 0) { // 앞 단어의 끝이랑 이어지는가?
			string pre = words[question_idx - 1];
			if (A[0] != pre[pre.length() - 1])
				continue;
		}

		if (question_idx < N - 1) { // 뒷 단어의 시작과 이어지는가?
			string nxt = words[question_idx + 1];
			if (A[A.length() - 1] != nxt[0])
				continue;
		}

		cout << A;
		break;
	}
}