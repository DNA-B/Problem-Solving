#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, K, cnt = 0;
int arr[BOUND];
/***********************/

void quick_sort(int p, int r);
int partition(int p, int r);

void check(int a, int b) {
	if (++cnt == K) {
		cout << min(a, b) << " " << max(a, b);
		exit(0);
	}
}

void quick_sort(int p, int r) {
	// A[p..r]을 오름차순 정렬한다.
	if (p < r) {
		int q = partition(p, r);  // 분할
		quick_sort(p, q - 1);  // 왼쪽 부분 배열 정렬
		quick_sort(q + 1, r);  // 오른쪽 부분 배열 정렬
	}
}

int partition(int p, int r) {
	int x = arr[r];    // 기준원소
	int idx = p - 1;   // idx는 x보다 작거나 작은 원소들의 끝지점

	for (int i = p; i < r; i++) {  // j는 아직 정해지지 않은 원소들의 시작 지점
		if (arr[i] <= x) {
			swap(arr[++idx], arr[i]); // i값 증가 후 A[i] <-> A[j] 교환
			check(arr[idx], arr[i]);
		}
	}

	if (idx + 1 != r) {
		swap(arr[idx + 1], arr[r]); // i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
		check(arr[idx + 1], arr[r]);
	}

	return idx + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	quick_sort(0, N - 1);
	cout << -1;

	return 0;
}