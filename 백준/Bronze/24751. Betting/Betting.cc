#include <bits/stdc++.h>
using namespace std;

int main() {
    double a;
    cin >> a;
    
    double ratio1 = 100.0 / a;
    double ratio2 = 100.0 / (100.0 - a);
    
    cout << fixed << setprecision(10);
    cout << ratio1 << '\n' << ratio2;
}