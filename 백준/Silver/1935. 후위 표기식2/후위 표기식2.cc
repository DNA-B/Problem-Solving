#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int num;

	stack<double> st;
	vector<int> trans;
	string fomula;

	int x;
	double op1, op2;

	cin >> num;
	cin >> fomula;
	
	for (int i = 0; i < num; i++)
	{
		cin >> x;
		trans.push_back(x);
	}

	for (int i = 0; i < fomula.size(); i++)
	{
		if (fomula[i] < 'A' || fomula[i] > 'Z')
		{
			op1 = st.top();
			st.pop();
			op2 = st.top();
			st.pop();
			
			switch (fomula[i])
			{
			case '+':
				st.push(op2 + op1);
				break;
			case '-':
				st.push(op2 - op1);
				break;
			case '*':
				st.push(op2 * op1);
				break;
			case '/':
				st.push(op2 / op1);
				break;
			}
			continue;
		}
		else
		{
			st.push(trans[fomula[i] - 'A']);
		}
	}

	printf("%.2lf", st.top());

	return 0;
}