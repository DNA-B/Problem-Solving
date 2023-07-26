#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, N;
priority_queue<int> max_q;
priority_queue<int, vector<int>, greater<>> min_q;
map<int, int> check;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        // clear
        max_q = {};
        min_q = {};
        check = {};

        cin >> N;

        char order;
        for (int i = 0; i < N; i++)
        {
            cin >> order;

            if (order == 'I') // 삽입
            {
                int x;

                cin >> x;

                max_q.emplace(x);
                min_q.emplace(x);
                check[x]++;
            }
            else if (order == 'D') // 삭제
            {
                int max_or_min;

                cin >> max_or_min;

                if (max_or_min == 1) // 최댓값 삭제
                {
                    if (!max_q.empty())
                    {
                        check[max_q.top()]--;
                        max_q.pop();
                    }
                }
                else if (max_or_min == -1) // 최솟값 삭제
                {
                    if (!min_q.empty())
                    {
                        check[min_q.top()]--;
                        min_q.pop();
                    }
                }

                while (!max_q.empty() && check[max_q.top()] < 1) // 최소에서 삭제된 값 비우기
                    max_q.pop();

                while (!min_q.empty() && check[min_q.top()] < 1) // 최대에서 삭제된 값 비우기
                    min_q.pop();
            }
        }

        if (max_q.empty() || min_q.empty())
            cout << "EMPTY\n";
        else
            cout << max_q.top() << " " << min_q.top() << "\n";
    }
    return 0;
}
