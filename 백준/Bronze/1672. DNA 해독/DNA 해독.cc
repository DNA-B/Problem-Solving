#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int n;
char table[4][4] = 
{
	{'A', 'C', 'A', 'G'},
	{'C', 'G', 'T', 'A'},
	{'A', 'T', 'C', 'G'},
	{'G', 'A', 'G', 'T'} 
};
string dna;

int index(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'G':
		return 1;
	case 'C':
		return 2;
	case 'T':
		return 3;
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> dna;

	while (n != 1)
	{
		dna[n - 2] = table[index(dna[n - 2])][index(dna[n - 1])];
		n--;
	}

	cout << dna[0];

    return 0;
}