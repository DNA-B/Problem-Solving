#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int jandon = 0;
    int taro;
    int res = 0;

    cin >> taro;
    
    jandon = 1000 - taro;

    res += jandon / 500;
    jandon -= 500 * (jandon / 500);

    res += jandon / 100;
    jandon -= 100 * (jandon / 100);

    res += jandon / 50;
    jandon -= 50 * (jandon / 50);

    res += jandon / 10;
    jandon -= 10 * (jandon / 10);

    res += jandon / 5;
    jandon -= 5 * (jandon / 5);

    res += jandon;

    cout << res;

    return 0;
}