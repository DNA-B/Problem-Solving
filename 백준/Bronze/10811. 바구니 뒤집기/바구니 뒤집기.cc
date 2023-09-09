#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int arr[101];

int main() 
{
    cin >> N >> M;

	for (int i = 1; i <= N; i++)
		arr[i] = i;

	for (int i = 0; i < M; i++)
	{
		int x, y;

		cin >> x >> y;
		reverse(arr + x, arr + y + 1);
	}

	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";

    return 0;
}