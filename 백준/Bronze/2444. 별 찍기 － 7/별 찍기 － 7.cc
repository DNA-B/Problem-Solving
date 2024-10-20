#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;

	for (int i = 1; i <= 2 * num - 1; i++) {
		if (i <= num) {
			for (int k = num - i; k > 0; k--)
				cout << " ";
		}
		else {
			for (int k = i - num; k > 0; k--)
				cout << " ";
		}
		
		if (i <= num) {
			for (int j = 2 * i - 1; j > 0; j--)
				cout << "*";
		}
		else {
			for (int j = 2 * (i - num) - 1; j < 2 * (num - 1); j++)
				cout << "*";
		}
        cout << "\n";
	}
    
	return 0;
}