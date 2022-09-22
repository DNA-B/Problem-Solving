#include <iostream>
#include <algorithm> 
#include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
#include <vector>
#include <list>
// #include <stack> 
// #include <bitset>

using namespace std;

int main() // 글자를 쓸 때와 지울 때 모두 기준은 에디터의 왼쪽임
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> l;
	auto iter = l.begin();
	string str;
	char order;
	char input_ch;
	int num;

	cin >> str;

	for (char ch:str)
	{
		l.push_back(ch);
	}
	iter = l.end(); // iter는 abc에서 c가 아니라 c의 다음 어떤 공간을 가르키는 중

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> order;

		switch (order)
		{
		case 'P':
		{
			cin >> input_ch;
			l.insert(iter, input_ch); // 글자를 쓰면 오른쪽에 커서가 있으므로 insert만
			break;
		}
		case 'L':
		{
			if (iter != l.begin()) iter--;
			break;
		}
		case 'D':
		{
			if (iter != l.end()) iter++;
			break;
		}
		case 'B':
		{
			if (iter != l.begin()) { 
				iter--; // 지울 때 내 왼쪽을 지운다.
				iter = l.erase(iter); // erase는 지우고 다음 값의 iter를 반환
			}
			break;
		}
		}
	}

	for (auto i : l)
	{
		cout << i;
	}
	
	return 0;
}