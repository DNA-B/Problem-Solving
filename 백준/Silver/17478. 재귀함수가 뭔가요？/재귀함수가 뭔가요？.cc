#include <bits/stdc++.h>

using namespace std;

int n;

void print_(string str, int rep) // 언더바 출력 함수
{
    for (int i = 0; i < rep; i++)
    {
        cout << "____"; // 4개
    }
    cout << str;
}

void rec_f(int count) // 재귀
{
    print_("\"재귀함수가 뭔가요?\"\n", count);
    if (count == n)
    {
        print_("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", count);
    }
    else
    {
        print_("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", count);
        print_("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", count);
        print_("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", count);
        rec_f(count + 1);
    }
    print_("라고 답변하였지.\n", count);
        
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    rec_f(0); // 언더바 출력은 0부터 n까지 가는게 편함.

    return 0;
}