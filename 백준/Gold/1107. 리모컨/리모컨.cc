#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX_GAP 500000

using namespace std;

string channel = "100"; // 초기 채널은 100번
string N;
int M;
int ans = INF; // min_gap
int broken[10]; // 부러진 숫자패드

void init_gap() // 초기 채널과 N의 gap으로 ans 초기화
{
    int gap = abs(stoi(N) - stoi(channel));

    ans = min(ans, gap);
    channel = "";
}

void solve(int cur)
{
    /*
    * N이 100이면 10000부터는 return;
    * 길이가 N보다 작을 때는 gap이 줄어들 수 있지만 N의 길이 + 1보다 커지는 경우 gap은 늘어난다.
    */

    if (cur > N.length() + 1)
        return;

    if (cur > 0) // cur가 0일 때 channel은 NULL 문자이므로 0보다 클 때
    {
        int tmp = to_string(stoi(channel)).length(); // 문자의 길이 -> 숫자키 클릭 횟수
        int gap = abs(stoi(N) - stoi(channel)); // (N - 현재 channel) -> + 혹은 - 몇 번 하는지

        if (gap >= MAX_GAP) // N이 500000까지이므로 그것보다 gap이 커지는 경우는 return;
            return;
        else // 그게 아니라면 ans 갱신
            ans = min(ans, gap + tmp); 
    }

    for (int i = 0; i < 10; i++) // 0 ~ 9까지이므로 나올 수 있는 모든 수의 조합 탐색
    {
        if (broken[i] != 1) // 부러지지 않았다면
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

    solve(0);
    cout << ans;

    return 0;
}
