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

	int cnt_str1[26] = { 0 };
	int cnt_str2[26] = { 0 };
	string str1, str2;
	int rep;
	bool flag = true;

	cin >> rep;

	for (int i = 0; i < rep; i++)
	{
		cin >> str1 >> str2;

		if (str2.size() <= str1.size()) // str2가 str1과 길이가 같거나 작아야 가능
		{
			for (int j = 0; j < str1.size(); j++) // str1 알파벳 카운팅
			{
				cnt_str1[str1[j] - 'a']++;
			}
			
			for (int j = 0; j < str2.size(); j++) // str2 알파벳 카운팅
			{
				cnt_str2[str2[j] - 'a']++;
			}

			for (int j = 0; j < str2.size(); j++) // 둘 비교
			{
				if (cnt_str1[str2[j] - 'a'] != cnt_str2[str2[j] - 'a'])
				{
					flag = false;
				}
			}
			
			if (flag)
			{
				cout << "Possible\n";
				fill(cnt_str1, cnt_str1 + 26, 0);
				fill(cnt_str2, cnt_str2 + 26, 0);
			}
			else
			{
				cout << "Impossible\n";
				flag = true;
				fill(cnt_str1, cnt_str1 + 26, 0);
				fill(cnt_str2, cnt_str2 + 26, 0);
			}
		}
		else // str2가 str1보다 길이가 클 때(불가능)
		{
			cout << "Impossible\n";
		}
		
	}
	
	return 0;
}