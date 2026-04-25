#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	int t, x, m;
	int answer = 0;
	cin >> t >> x >> m;
 
	int d, s;
	int minV = 10000000;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		minV = min(minV, (d - 1) / s);
	}
 
	
	if (t >= minV) {
		answer = x * (minV + (t - minV) / 2);
	} 
	if (t < minV) {
		answer = x * t;
	}
	// 몬스터 때문에 아예 금화 파밍을 못하는 경우
	if (minV == 0){ 
		answer = 0;
	}
	// 몬스터가 0마리인 경우
	if (m == 0) {
		answer = x * t;
	}
 
	cout << answer;
 
}