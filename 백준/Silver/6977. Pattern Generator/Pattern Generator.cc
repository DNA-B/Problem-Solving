#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int T, N, K;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int T; 
    cin >> T;

    while(T--) {
        int N, M; 
        cin >> N >> M;

        vector<int> v(N);
        for(int i=0; i<M; i++) 
            v[i] = 1;

        cout << "The bit patterns are\n";

        while(true) {
            for(int i=0; i<N; i++) 
                cout << v[i];
            cout << "\n";

            if(!prev_permutation(v.begin(), v.end())) 
                break;
        }

        cout << "\n";
    }
}