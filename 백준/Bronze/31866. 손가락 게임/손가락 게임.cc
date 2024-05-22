#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 200001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int js, ij;
/***********************/

void special_case() {
	if (js != 0 && js != 2 && js != 5) { // 서로 다른 무효값
		if (ij != 0 && ij != 2 && ij != 5)
			cout << "=";
		else // 익준이가 가위, 바위, 보면 승리 
			cout << "<";
	}
	else if (ij != 0 && ij != 2 && ij != 5) { // 서로 다른 무효값
		if (js != 0 && js != 2 && js != 5)
			cout << "=";
		else // 준성이가 가위, 바위, 보면 승리 
			cout << ">";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> js >> ij;

	if (js == ij)
		cout << "=";
	else if (js == 0 && ij == 2) // 바위, 가위
		cout << ">";
	else if (js == 0 && ij == 5) // 바위, 보
		cout << "<";
	else if (js == 2 && ij == 0) // 가위, 바위
		cout << "<";
	else if (js == 2 && ij == 5) // 가위, 보
		cout << ">";
	else if (js == 5 && ij == 0) // 보, 바위
		cout << ">";
	else if (js == 5 && ij == 2) // 보, 가위
		cout << "<";
	else
		special_case();

	return 0;
}