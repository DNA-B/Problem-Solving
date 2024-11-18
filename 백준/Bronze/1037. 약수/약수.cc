#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
    vector<int> v;
	
	cin >> n;

	for (int x, i = 0; i < n; i++) {
		cin >> x;
        v.push_back(x);
	}
    
    sort(v.begin(), v.end());
	cout << v.front() * v.back();
}