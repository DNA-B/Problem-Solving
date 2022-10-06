#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m1, m2, m3, m4, m_total;
	int s1, s2, s3, s4, s_total;

	cin >> m1 >> m2 >> m3 >> m4;
	m_total = m1 + m2 + m3 + m4;
	cin >> s1 >> s2 >> s3 >> s4;
	s_total = s1 + s2 + s3 + s4;

	cout << max(m_total, s_total);

	return 0;
}