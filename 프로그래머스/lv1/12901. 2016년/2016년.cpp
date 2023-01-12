#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> v = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int cur = v.size() -  2; // v인덱스 연제 1월 1일은 금요일
    int cur_month = 1, cur_day = 1; // 현재 1월 1일
    
    while(cur_month < a)
    {
        if(cur_month == 1)
        {
            for(int i = 0;i<31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 2)
        {
            for(int i = 0;i<29;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 3)
        {
            for(int i = 0;i < 31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 4)
        {
            for(int i = 0;i<30;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 5)
        {
            for(int i = 0;i<31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 6)
        {
            for(int i = 0;i < 30;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 7)
        {
            for(int i = 0;i<31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 8)
        {
            for(int i = 0;i<31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 9)
        {
            for(int i = 0;i<30;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 10)
        {
            for(int i = 0;i<31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 11)
        {
            for(int i = 0;i<30;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }
        else if(cur_month == 12)
        {
            for(int i = 0;i<31;i++)
            {
                if(cur > 0)
                {
                    if(cur % 6 == 0)
                        cur = 0;
                    else
                        cur++;
                }
                else
                    cur++;
            }
            cur_month++;
        }   
    }
    
    while(cur_day < b)
    {
        if(cur > 0)
        {
            if(cur % 6 == 0)
                cur = 0;
            else
                cur++;
        }
        else
            cur++;
        
        cur_day++;
    }
    
    answer = v[cur];
    return answer;
    
}