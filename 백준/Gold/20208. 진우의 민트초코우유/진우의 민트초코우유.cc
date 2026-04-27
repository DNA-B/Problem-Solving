#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n, m, h;
int sx, sy;
int ans;

vector<pair<int, int>> point;
vector<int> visited;
 
void recur(int x, int y, int health, int cnt) {
    int go_home = abs(x - sx) + abs(y - sy);
    if (health >= go_home) {
        ans = max(ans, cnt);
    }
 
    for (int i = 0; i < point.size(); i++) {
        int need_hp = abs(x - point[i].first) + abs(y - point[i].second);
        
        if (visited[i]) continue;
        if (health < need_hp) continue;
        
        visited[i] = 1;
        recur(point[i].first, point[i].second, health - need_hp + h, cnt + 1);
        visited[i] = 0;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m >> h;
 
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;

            if (a == 1)
                sx = i, sy = j;
            else if (a == 2)
                point.push_back(make_pair(i, j));
        }
    }
    
    visited.resize(point.size(), 0);
    recur(sx, sy, m, 0);
    cout << ans;
 
    return 0;
}