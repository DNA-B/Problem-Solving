#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int a;
    int b = 0;
    cin >> a;

    if (a == 1010) {     
        cout << 20;
    }
    else if (a % 10 == 0) {   
        a /= 100;
        cout << 10 + a;
    }
    else {
        b += a % 10;
        a /= 10;
        if (a == 10) {   
            cout << 10 + b;
        }
        else {           
            cout << a + b;
        }
    }

	return 0;
}