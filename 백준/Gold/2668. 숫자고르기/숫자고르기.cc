#include <bits/stdc++.h>

using namespace std;

int N;
int r; // cycle 확인용 변수 (시작값 저장)
int arr[101];
int vis[101];
set<int> ans; // 집합이므로 set 사용 (중복제거)

void dfs(int cur) 
{
    if (vis[cur]) // 이미 방문했는데
    {
        if (cur == r) // 부모로 돌아온다면 cycle
            ans.insert(r);  
    }
    else
    {
        vis[cur] = true;
        dfs(arr[cur]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++)
    {
        fill(vis, vis + 101, 0); // vis 초기화 시키면서 전체 dfs 돌기
        r = i;
        dfs(i);
    }

    cout << ans.size() << "\n";
    
    for (auto item : ans)
        cout << item << "\n";

    return 0;
}