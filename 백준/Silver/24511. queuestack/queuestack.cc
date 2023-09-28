#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;
int dq_type[1000001];
deque<int> dq;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> dq_type[i];

    for (int i = 0; i < N; i++)
    {
        int x;

        cin >> x;

        if (dq_type[i] == 1)
            continue;
        else
            dq.push_back(x);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x;

        cin >> x;

        dq.push_front(x);
        ans.push_back(dq.back());
        dq.pop_back();
    }

    for (auto item : ans)
        cout << item << " ";

    return 0;
}
