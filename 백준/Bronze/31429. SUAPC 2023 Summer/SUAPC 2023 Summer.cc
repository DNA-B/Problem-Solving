#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
map<int, pair<int, int>> m = {
	{1, {12, 1600}},
	{2, {11, 894}},
	{3, {11, 1327}},
	{4, {10, 1311}},
	{5, {9, 1004}},
	{6, {9, 1178}},
	{7, {9, 1357}},
	{8, {8, 837}},
	{9, {7, 1055}},
	{10, {6, 556}},
	{11, {6, 773}} };
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	cout << m[N].X << " " << m[N].Y;

	return 0;
}