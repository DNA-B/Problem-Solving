#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double ans;

    scanf("%d", &n);
    ans = pow(0.5, n);
    printf("%.*lf", n, ans);
}
