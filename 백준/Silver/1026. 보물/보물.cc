#include <bits/stdc++.h>

using namespace std;

vector<int> a(51);
vector<int> b(51);

// 1026번 : 보물
// B를 재배열하면 안된다는 것은 A와 B를 짝지어주라는 것
// 그렇다면 곱들이 평균에 가깝게하기 위해 B가 클수록 A는 작아지면된다.
// A 오름차순 sort & B 내림차순 sort

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int res = 0;
   
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
   
    for (int i = 0; i < n; i++)
        cin >> b[i];
    

    sort(a.begin(), a.begin() + n);
    sort(b.begin(), b.begin() + n, greater<int>());

    for (int i = 0; i < n; i++)
    {    
        res += a[i] * b[i];
    }

    cout << res;

    return 0;
}