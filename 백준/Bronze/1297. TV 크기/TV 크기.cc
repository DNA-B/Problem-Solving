#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

int D, H, W;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> D >> H >> W;

	double l = sqrt((W * W) + (H * H));
	double x = W * D / l;
	double y = H * D / l;

	cout << (int)y << " " << (int)x;


    return 0;
}