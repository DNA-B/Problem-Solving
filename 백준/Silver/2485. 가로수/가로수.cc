#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, tmp = 0, ans = 0;
vector<int> v, diff; // 점 사이의 차이 저장 변수

int gcd(int a, int b) { // 유클리드 호제법
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size() - 1; i++) // 차이 저장
        diff.push_back(v[i + 1] - v[i]);

    int tmp = diff[0]; 
    for (int i = 0; i < diff.size(); i++) // 차이들의 gcd 계산
        tmp = gcd(diff[i], tmp);

    int st = v.front(), en = v.back();
    for (int i = st; i <= en; i += tmp)
        ans++;

    cout << ans - v.size(); // 모든 점의 개수 - 입력으로 받은 점의 개수

    return 0;
}
