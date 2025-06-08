#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << n << " is " << ((n & 1) ? "odd" : "even");
    return 0;
}