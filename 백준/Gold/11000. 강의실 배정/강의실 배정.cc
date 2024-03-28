#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/*
input
8
1 8
3 7
5 6
6 11
8 10
9 16
10 14
11 12

for문에서 우선순위 큐의 순서
8
7 -> 8
6 -> 7 -> 8
7 -> 8 -> 11 (6 삭제)
8 -> 10 -> 11 (7 삭제)
10 -> 11 -> 16 (8 삭제)
11 -> 14 -> 16 (10 삭제)
12 -> 14 -> 16 (11 삭제)
*/

int N;
pair<int, int> lecture[200001];
priority_queue<int, vector<int>, greater<>> pq; // end time만 넣고, 최소힙

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> lecture[i].first >> lecture[i].second;

	sort(lecture, lecture + N); // start 기준 오름차순 정렬
	pq.push(lecture[0].second); // 자연스럽게 시작, 끝 간격이 가장 작은 순으로 검사할 수 있다.
    
	for (int i = 1; i < N; i++)
	{
		if (pq.top() <= lecture[i].first)
			pq.pop();

		pq.push(lecture[i].second);
	}

	cout << pq.size();

	return 0;
}