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
int year, channel, day;
string month, start, length;
unordered_map<string, int> Month = {
	 {"January", 1}, {"February", 2}, {"March", 3},
	 {"April", 4},   {"May", 5},      {"June", 6},
	 {"July", 7},    {"August", 8},   {"September", 9},
	 {"October", 10},{"November", 11},{"December", 12}
};

//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	string tmp; // Channel
	char comma;
	while (cin >> tmp >> channel >> comma >> month >> day >> year >> comma >> start >> length) {
		unsigned int VCR = 0;
		VCR |= ((year - 1994) << 25);
		VCR |= (channel << 19);
		VCR |= (Month[month] << 15);
		VCR |= (day << 10);

		//============= parsing ===============
		int colon = start.find(":");
		int hour = stoi(start.substr(0, colon));
		int minute = stoi(start.substr(colon + 1, 2));
		string am_pm = start.substr(colon + 3);

		if (am_pm == "am" && hour == 12)
			hour = 0;
		if (am_pm == "pm" && hour != 12)
			hour += 12;
		//=====================================

		int total_start_time = (hour * 60 + minute) / 30;
		VCR |= (total_start_time << 4);
		VCR |= (stoi(length) / 30);

		cout << VCR << "\n";
	}
}