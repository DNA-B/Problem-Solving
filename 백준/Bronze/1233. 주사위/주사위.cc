#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int s1, s2, s3;
int arr[101];
int v_max = 0, ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> s1 >> s2 >> s3;

	for (int i = 1; i <= s1; i++)
		for (int j = 1; j <= s2; j++)
			for (int k = 1; k <= s3; k++)
				arr[i + j + k]++;

	for (int i = 1; i <= 80; i++)
		if (arr[i] > v_max)
			v_max = arr[i], ans = i;

	cout << ans;

    return 0;
}