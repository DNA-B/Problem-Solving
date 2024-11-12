#include <iostream>
#include <algorithm> 
#include <string> 
#include <vector>
#include <list>

using namespace std;

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	list<int> l;
	list<int>::iterator it;
	int count = 1, n, n_cut;

	cin >> n >> n_cut;

	for (int i = 1; i <= n; i++)
		l.push_back(i);

	it = l.begin();

	cout << '<';
	while (l.size() != 1) {
		if (it == l.end())
			it = l.begin();

		if (count % n_cut == 0) {
			cout << *it << ", ";
			it = l.erase(it);
			count = 1;
		}
		else {
			it++;
			count++;
		}
	}
    
	cout << l.front() << '>';
	return 0;
}