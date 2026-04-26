#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int sum = 0, XOR = 0;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		XOR ^= arr[i];
	}
	if (XOR == 0) {
		sort(arr.begin(), arr.end());
		cout << sum - arr[0];
	}
	else
		cout << 0;
	return 0;
}