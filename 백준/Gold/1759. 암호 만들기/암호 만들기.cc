#include <bits/stdc++.h>

using namespace std;

int l, c;
char arr[16];
char num[16];
bool isused[27];
int mo = 0;
int ja = 0;


void func(int k, int st)
{ // 현재 k개까지 수를 택했음.
    if (k == l)
    {
        for (int i = 0; i < l; i++)
        { // 자음, 모음 개수
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                mo++;
            else
                ja++;
        }

        if (mo >= 1 && ja >= 2 && mo <= ja) // 모음이 1개 이상 이기만 하면 되지만 자음도 2개 이상이어야함
        {
            for (int i = 0; i < l; i++)
            {
                cout << arr[i];
            }
            cout << '\n';
        }

        mo = 0;
        ja = 0;

        return;
    }

    for (int i = st; i < c; i++) // i = (st = i+1)로 받아서 사전순 진행
    {
        if (!isused[num[i] - 'a'])
        {
            arr[k] = num[i];
            isused[num[i] - 'a'] = true;
            func(k + 1, i + 1); // 사전순 >> i가 s보다 뒤에 올 수 없음 i를 한 칸씩 밀어서 재귀호출
            isused[num[i] - 'a'] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    
    for (int i = 0; i < c; ++i)
    {
        cin >> num[i];
    }

    sort(num, num + c);
    func(0, 0);

    return 0;
}
