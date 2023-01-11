using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long total_price = 0;
    int cur = 1;
    
    for(int i = 0;i < count;i++)
    {
        total_price += price * cur;
        cur++;
    }
    
    if(money >= total_price)
        return 0;
    else
        answer = total_price - money;
    
    return answer;
}