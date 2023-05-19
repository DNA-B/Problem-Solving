#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    string sentence;
    stack <char> st;

    cin >> T;
    cin.ignore();

    while (T--)
    {
        getline(cin, sentence);
        sentence += ' ';

        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else
                st.push(sentence[i]);
        }cout << "\n";
    }

    return 0;
}