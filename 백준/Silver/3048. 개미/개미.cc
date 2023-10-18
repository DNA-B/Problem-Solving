#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9
#define MOD 1000000000

using namespace std;

int N1, N2, T;
string first, second;
string st, en;
map<char, int> m; // {ant, team}
bool is_move[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N1 >> N2;
    cin >> first >> second;
    cin >> T;

    for (int i = 0; i < N1; i++)
        m[first[i]] = 1;

    for (int i = 0; i < N2; i++)
        m[second[i]] = 2;

    reverse(first.begin(), first.end());

    st = first + second;
    en = second + first;

    int len = N1 + N2;
    int cnt = 0;
    while (st != en)
    {
        fill(is_move, is_move + 26, false);

        if (cnt == T)
            break;

        for (int i = 0; i < len; i++) // 전체가 1초
        {
            if (m[st[i]] == 1 && !is_move[st[i] - 'A']) // 1번팀 개미 && 이번 초에 움직이지 않았다면 -> 오른쪽 진행
            {
                if ((i != len - 1) && (m[st[i + 1]] == 2) && (!is_move[st[i + 1] - 'A'])) // 맨 오른쪽이 아니고 내 다음 개미가 2번팀이이면서 움직이지 않았다면
                {
                    swap(st[i], st[i + 1]);
                    is_move[st[i] - 'A'] = true;
                    is_move[st[i + 1] - 'A'] = true;
                }
            }
            else if (m[st[i]] == 2 && !is_move[st[i] - 'A']) // 2번팀 개미 && 이번 초에 움직이지 않았다면 -> 왼쪽 진행
            {
                if ((i != 0) && (m[st[i - 1]] == 1) && (!is_move[st[i - 1] - 'A'])) // 맨 왼쪽이 아니고 내 전의 개미가 1번팀이면서 움직이지 않았다면
                {
                    swap(st[i], st[i - 1]);
                    is_move[st[i] - 'A'] = true;
                    is_move[st[i - 1] - 'A'] = true;
                }
            }
        }

        cnt++;
    }

    cout << st;

    return 0;
}
