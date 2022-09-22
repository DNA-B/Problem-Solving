#include <iostream>
#include <algorithm> 
#include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
#include <vector>
// #include <list>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string dna[1001];
	int nc[4] = { 0 }; // A, C, G, T
	int dist = 0;
	int max = -1;
	int index = -1;
	int rep, len;

	cin >> rep >> len;

	

	for (int i = 0; i < rep; i++)
	{

		cin >> dna[i];
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < rep; j++)
		{
			switch (dna[j][i])
			{
			case 'A':
				nc[0]++;
				break;
			case 'C':
				nc[1]++;
				break;
			case 'G':
				nc[2]++;
				break;
			case 'T':
				nc[3]++;
				break;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			if (max < nc[k])
			{
				max = nc[k];
				index = k;
			}
		}

		switch (index)
		{
		case 0:
			cout << 'A';
			break;
		case 1:
			cout << 'C';
			break;
		case 2:
			cout << 'G';
			break;
		case 3:
			cout << 'T';
			break;
		}

		dist += (rep - max);
		max = -1;
		index = -1;
		fill(nc, nc + 4, 0);
	}


	cout << "\n" << dist;

	return 0;
}