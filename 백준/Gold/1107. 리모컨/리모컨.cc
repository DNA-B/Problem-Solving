#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_GAP 500000

using namespace std;

string channel = "100";
string N;
int M;
int ans = INF;
int broken[10];

void init_gap()
{
    int gap = abs(stoi(N) - stoi(channel));

    ans = min(ans, gap);
    channel = "";
}

void solve(int cur)
{
    if (cur > N.length() + 1)
        return;

    if (cur > 0)
    {
        int tmp = to_string(stoi(channel)).length();
        int gap = abs(stoi(N) - stoi(channel));

        if (gap >= MAX_GAP)
            return;
        else
            ans = min(ans, gap + tmp);
    }

    for (int i = 0; i < 10; i++)
    {
        if (broken[i] != 1)
        {
            channel.push_back(i + '0');
            solve(cur + 1);
            channel.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    init_gap();

    for (int i = 0; i < M; i++)
    {
        int x;

        cin >> x;
        broken[x] = 1;
    }

    if (N == "100")
    {
        cout << 0;
        return 0;
    }

    solve(0);
    cout << ans;

    return 0;
}
