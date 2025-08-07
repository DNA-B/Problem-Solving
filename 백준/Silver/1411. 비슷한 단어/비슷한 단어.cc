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
int N, res = 0;
vector<string> words;
//=========================//

bool chk(string a, string b) {
	int vis[26] = { 0, };
	char trans[26] = { '\0', };
    
	for (int i = 0; i < a.size(); i++) { // 같은 것들 미리 처리
		if (a[i] == b[i])
			vis[b[i] - 'a'] = 1;
	}

	for (int i = 0; i < a.size(); i++) { // 서로 다른 알파벳 매핑
		if (vis[b[i] - 'a'])
			continue;
		if (trans[a[i] - 'a'] == '\0') {
			trans[a[i] - 'a'] = b[i];
			vis[b[i] - 'a'] = 1;
		}
	}

	for (int i = 0; i < a.size(); i++) { // 변환
		if (trans[a[i] - 'a'] != '\0')
			a[i] = trans[a[i] - 'a'];
	}

	return a == b;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		words.push_back(tmp);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (chk(words[i], words[j]))
				res++;
		}
	}

	cout << res;
}