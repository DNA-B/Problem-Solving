#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, N;
multiset<int> ms;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        // clear
        ms = {};

        cin >> N;

        char order;
        int x;
        while (N--)
        {
            cin >> order >> x;

            if (order == 'I') // 삽입
            {
                ms.emplace(x);
            }
            else if (order == 'D') // 삭제
            {
                if (ms.empty())
                    continue;

                if (x == 1) // 최댓값 삭제
                    ms.erase(--ms.end());
                else if (x == -1) // 최솟값 삭제
                    ms.erase(ms.begin());
            }
        }

        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *(--ms.end()) << " " << *ms.begin() << "\n";
    }

    return 0;
}
