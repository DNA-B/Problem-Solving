#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    string answer;
    int total;

    cin >> str1 >> str2;
    
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    total = stoi(str1) + stoi(str2);
    answer = to_string(total);
    reverse(answer.begin(), answer.end());

    cout << stoi(answer);

    return 0;
}