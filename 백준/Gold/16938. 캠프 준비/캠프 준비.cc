#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <stdio.h>
using namespace std;
int N, L, R, X, res = 0;
int diff[20], arr[20];
void solve(int cnt, int idx) {
	if (cnt > N) return;
	if (cnt >= 2 && arr[cnt - 1] - arr[0] >= X) {
		long long total = accumulate(arr, arr + cnt, 0LL);
		if (L <= total && total <= R) res++;
		else if (total > R) return;}
	for (int i = idx; i < N; i++) {arr[cnt] = diff[i];solve(cnt + 1, i + 1);}}
int main() {
	scanf("%d %d %d %d", &N, &L, &R, &X);
	for (int i = 0; i < N; i++)scanf("%d", &diff[i]);
	sort(diff, diff + N);solve(0, 0);printf("%d", res);
	return 0;}