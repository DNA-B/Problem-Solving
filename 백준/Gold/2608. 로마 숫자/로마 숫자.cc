#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/*
			{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}

			IV = 4
			IX = 9
			XL = 40
			XC = 90
			CD = 400
			CM = 900

			V, L, D는 한 번만 사용할 수 있고,
			I, X, C, M은 연속해서 세 번까지만 사용할 수 있다

			4부터는 -> IV?
			40부터는 -> XL?
			400부터는 -> CD?

			모든 수는 가능한 가장 적은 개수의 로마 숫자들로 표현
*/


string s1, s2, ans_to_string;
int s1_to_int, s2_to_int, ans;
map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

int special_case_to_int(string s, int idx)
{
	if (idx != s.size() - 1 && s[idx] == 'I' && s[idx + 1] == 'V')
		return 4;
	else if (idx != s.size() - 1 && s[idx] == 'I' && s[idx + 1] == 'X')
		return 9;
	else if (idx != s.size() - 1 && s[idx] == 'X' && s[idx + 1] == 'L')
		return 40;
	else if (idx != s.size() - 1 && s[idx] == 'X' && s[idx + 1] == 'C')
		return 90;
	else if (idx != s.size() - 1 && s[idx] == 'C' && s[idx + 1] == 'D')
		return 400;
	else if (idx != s.size() - 1 && s[idx] == 'C' && s[idx + 1] == 'M')
		return 900;

	return 0;
}

int rtoi(string s)
{
	int total = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int is_special_case = special_case_to_int(s, i);

		if (is_special_case)
		{
			total += is_special_case;
			i++;
			continue;
		}

		total += m[s[i]];
	}

	return total;
}

string special_case_to_string(int digit, string st, string mid, string en)
{
	string tmp = "";

	switch (digit)
	{
	case 1:
	case 2:
	case 3:
		while (digit--)
			tmp += st;
		break;
	case 4:
		tmp += st + mid;
		break;
	case 5:
		tmp += mid;
		break;
	case 6:
	case 7:
	case 8:
		tmp += mid;
		digit -= 5;

		while (digit--)
			tmp += st;

		break;
	case 9:
		tmp += st + en;
		break;
	}

	return tmp;
}

string itor(int n)
{
	vector<int> digit;
	string total = "";
	int pow = 1;

	while (n != 0)
	{
		digit.push_back((n % 10) * pow);
		n /= 10;
		pow *= 10;
	}

	reverse(digit.begin(), digit.end());

	for (int i = 0; i < digit.size(); i++)
	{
		if ((digit[i] / 1000) != 0)
		{
			digit[i] /= 1000;

			while (digit[i]--)
				total += 'M';
		}
		else if ((digit[i] / 100) != 0)
		{
			digit[i] /= 100;
			total += special_case_to_string(digit[i], "C", "D", "M");
		}
		else if ((digit[i] / 10) != 0)
		{
			digit[i] /= 10;
			total += special_case_to_string(digit[i], "X", "L", "C");
		}
		else
			total += special_case_to_string(digit[i], "I", "V", "X");
	}

	return total;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> s1 >> s2;

	ans = rtoi(s1) + rtoi(s2);

	cout << ans << "\n";
	cout << itor(ans);

	return 0;
}