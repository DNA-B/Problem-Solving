#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; // 수열 배열
bool isused[10]; // 수의 사용 여부

void func(int k) { // 현재 k개까지 수를 택했음.
    if (k == m) { // m개를 모두 택했으면
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr 출력
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) { // 1부터 n까지의 수에 대해
        if (!isused[i]) { // 아직 i가 사용되지 않았으면
            arr[k] = i; // 수열의 k번째 수를 i로 정함
            isused[i] = 1; // i 사용 표시
            func(k + 1); // 다음 수를 정하기 위해 func(k + 1) 호출
            isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 명시함.
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);

    return 0;
}