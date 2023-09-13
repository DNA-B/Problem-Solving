#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int a_m, a_s, b_m, b_s;
int mother, son;
int g;

int get_gcd(int a, int b)
{
    return b ? get_gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a_s >> a_m;
    cin >> b_s >> b_m;

    mother = a_m * b_m;
    son = (a_s * b_m) + (b_s * a_m);
    g = get_gcd(son, mother);

    cout << son / g << " " << mother / g;

    return 0;
}
