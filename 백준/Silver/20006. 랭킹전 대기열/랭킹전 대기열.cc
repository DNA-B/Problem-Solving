#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int P, M;
int level;
string name;
map<string, int> m[301]; // {name, level}
int first_value[301];

void check_room(int room_number, string name, int level)
{
    if (m[room_number].size() == 0)
    {
        m[room_number][name] = level;
        first_value[room_number] = level;
        return;
    }

    if (m[room_number].size() < M)
    {
        int sub_level = abs(level - first_value[room_number]);

        if (sub_level <= 10)
        {
            m[room_number][name] = level;
            return;
        }
    }

    check_room(room_number + 1, name, level);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> P >> M;

    for (int i = 0; i < P; i++)
    {
        cin >> level >> name;
        check_room(0, name, level);
    }

    for (int i = 0; m[i].size() != 0; i++)
    {
        if (m[i].size() == M)
            cout << "Started!\n";
        else
            cout << "Waiting!\n";

        for (auto item : m[i])
            cout << item.second << " " << item.first << "\n";
    }

    return 0;
}