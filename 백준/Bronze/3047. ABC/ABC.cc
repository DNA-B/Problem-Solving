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
string S;
int x, y, z, A, B, C;
vector<int> nums;
unordered_map<char, int> order;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> x >> y >> z >> S;

	nums = { x, y, z };
	sort(nums.begin(), nums.end());

	order['A'] = nums[0];
	order['B'] = nums[1];
	order['C'] = nums[2];

	for (char c : S)
		cout << order[c] << ' ';
}