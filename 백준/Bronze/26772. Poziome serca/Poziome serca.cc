#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const string heart[9] = {
    " @@@   @@@ ",
    "@   @ @   @",
    "@    @    @",
    "@         @",
    " @       @ ",
    "  @     @  ",
    "   @   @   ",
    "    @ @    ",
    "     @     "
  };

  int n; cin >> n;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < n; j++) {
      cout << heart[i];
      if (j != n - 1) cout << " ";
    }
    cout << "\n";
  }

  return 0;
}