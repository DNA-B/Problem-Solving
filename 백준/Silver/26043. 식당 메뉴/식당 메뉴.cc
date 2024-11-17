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
int N;
queue <pair<int, int>> line;
queue<int> meal;
vector<int> prefer, no_prefer, no_meal;
//=========================//

void print(vector<int> v) {
	if (v.empty()) {
		cout << "None\n";
		return;
	}

	sort(v.begin(), v.end());

	for (int stu : v)
		cout << stu << ' ';
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		int order, a, b;

		cin >> order;
		if (order == 1) {
			cin >> a >> b;
			line.push({ a, b });
		}
		else {
			cin >> b;
			meal.push(b);
		}
	}

	while (!meal.empty()) {
		int cur = meal.front(); meal.pop();
		auto [stu, want] = line.front(); line.pop();

		if (want != cur)
			no_prefer.push_back(stu);
		else
			prefer.push_back(stu);
	}

	while (!line.empty()) {
		auto [stu, want] = line.front(); line.pop();
		no_meal.push_back(stu);
	}

	print(prefer); print(no_prefer); print(no_meal);
}