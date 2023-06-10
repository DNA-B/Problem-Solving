#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

int N, M;
char sep = ','; // seperater
string str; // input value
unordered_set<string> s; // vocab

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        s.insert(str);
    }

    while (M--)
    {
        cin >> str;

        std::istringstream iss(str);
        std::string str_buf;

        while (getline(iss, str_buf, sep))
            s.erase(str_buf);

        cout << s.size() << "\n";
    }

    return 0;
}