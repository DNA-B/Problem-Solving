#include <iostream>
#include <algorithm>

using namespace std;

#define fastIO (ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define nl '\n'

struct AP {
	int atk;
	int pop;
};

int N, K;
AP ap[20];
int maxPop;

void Find(int prefixSum, int fatigability, int totalPop, int index) {
	for (int i = index; i < N; i++) {
		int nextFatigability = fatigability + ap[i].atk;
		int nextTotalPop = totalPop + ap[i].pop;
		int nextPrefixSum = prefixSum + nextFatigability;
		if (nextPrefixSum > K) break;

		maxPop = max(maxPop, nextTotalPop);
		Find(nextPrefixSum, nextFatigability, nextTotalPop, i + 1);
	}
}

int main() {
	fastIO;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> ap[i].atk;
	for (int i = 0; i < N; i++)
		cin >> ap[i].pop;

	sort(ap, ap + N, [](AP &a, AP &b) {
		return a.atk < b.atk;
	});

	Find(0, 0, 0, 0);
	cout << maxPop;

	return 0;
}