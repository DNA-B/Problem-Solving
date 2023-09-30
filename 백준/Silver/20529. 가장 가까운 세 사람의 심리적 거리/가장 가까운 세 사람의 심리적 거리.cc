#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int T, N;

int solve(string a, string b, string c)
{
    int dist = 0;

    for (int i = 0; i < 4; i++)
        dist += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);

    return dist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        vector<string> mbti;
        int min_dist = INF;

        cin >> N;


        for (int i = 0; i < N; i++)
        {
            string s;

            cin >> s;
            mbti.push_back(s);
        }

        if (N > 32) // mbti 유형은 16개, 이 때 32개가 들어온다면 반드시 1개의 유형은 겹친다. 여기서 33개가 된다면 3개가 겹치는 유형이 반드시 생기므로 최소 거리는 0이다.
        {
            cout << 0 << "\n";
            continue;
        }

        for (int i = 0; i < N - 2; i++)
            for (int j = i + 1; j < N - 1; j++)
                for (int k = j + 1; k < N; k++)
                    min_dist = min(min_dist, solve(mbti[i], mbti[j], mbti[k]));

        cout << min_dist << "\n";
    }

    return 0;
}
