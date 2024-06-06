#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
string arr[3];
int idx = 0;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];

		/*
		Fizz와 Buzz는 무조건 거리가 1 혹은 2 차이가 난다.
		즉, 3개의 입력 중에 1개는 무조건 숫자가 오는 것이다. 이 숫자를 이용해서 다음에 올 문자열을 예측하면 된다.
		*/
		if (arr[i] != "Fizz" && arr[i] != "Buzz" && arr[i] != "FizzBuzz")
			idx = stoi(arr[i]);
		else
			idx == 0 ? idx : idx++;
	}

	idx++; // 다음수를 예측해야하므로 +1

	if (idx % 3 == 0 & idx % 5 == 0)
		cout << "FizzBuzz";
	else if (idx % 3 == 0)
		cout << "Fizz";
	else if (idx % 5 == 0)
		cout << "Buzz";
	else
		cout << idx;

	return 0;
}