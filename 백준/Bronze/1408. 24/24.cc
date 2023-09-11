#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int cur_h, cur_m, cur_s;
int st_h, st_m, st_s;
int diff_h, diff_m, diff_s;

void print_time()
{
    if (diff_h < 10)
        printf("0%d:", diff_h);
    else
        printf("%d:", diff_h);

    if (diff_m < 10)
        printf("0%d:", diff_m);
    else
        printf("%d:", diff_m);

    if (diff_s < 10)
        printf("0%d", diff_s);
    else
        printf("%d", diff_s);
}

int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);*/

    scanf("%d:%d:%d", &cur_h, &cur_m, &cur_s);
    scanf("%d:%d:%d", &st_h, &st_m, &st_s);

    if (st_s - cur_s < 0)
    {
        diff_s = (st_s + 60) - cur_s;
        st_m--;
    }
    else
        diff_s = st_s - cur_s;
       
    if (st_m - cur_m < 0)
    {
        diff_m = (st_m + 60) - cur_m;
        st_h--;
    }
    else
        diff_m = st_m - cur_m;

    if (st_h - cur_h < 0)
        diff_h = (st_h + 24) - cur_h;
    else
        diff_h = st_h - cur_h;

    print_time();

    return 0;
}
