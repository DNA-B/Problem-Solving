#include <bits/stdc++.h>
#define MAX_SIZE ('Z'+ 1)

using namespace std;

string word;
map<char, char> m = {
    {'D', 'A'}, {'E', 'B'}, {'F', 'C'},
    {'G', 'D'}, {'H', 'E'}, {'I', 'F'},
    {'J', 'G'}, {'K', 'H'}, {'L', 'I'},
    {'M', 'J'}, {'N', 'K'}, {'O', 'L'},
    {'P', 'M'}, {'Q', 'N'}, {'R', 'O'},
    {'S', 'P'}, {'T', 'Q'}, {'U', 'R'},
    {'V', 'S'}, {'W', 'T'}, {'X', 'U'},
    {'Y', 'V'}, {'Z', 'W'}, {'A', 'X'},
    {'B', 'Y'}, {'C', 'Z'},
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> word;

    for (auto item : word)
        cout << m[item];

    return 0;
}
