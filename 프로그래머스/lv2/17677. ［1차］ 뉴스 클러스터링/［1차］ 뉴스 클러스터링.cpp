#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> A;
    map<string, int> B;
    double inter = 0;
    double uni = 0;

    for(int i = 0; i < str1.length() - 1; i++)
    {
        if(('A' <= str1[i] && str1[i] <= 'Z') || ('a' <= str1[i] && str1[i] <= 'z'))
        {
            if(('A' <= str1[i+1] && str1[i+1] <= 'Z') || ('a' <= str1[i+1] && str1[i+1] <= 'z'))
            {
                string tmp = str1.substr(i, 2);
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                A[tmp]++;
            }
        }
    }

    for(int i = 0; i < str2.length() - 1; i++)
    {  
        if(('A' <= str2[i] && str2[i] <= 'Z') || ('a' <= str2[i] && str2[i] <= 'z'))
        {
            if(('A' <= str2[i+1] && str2[i+1] <= 'Z') || ('a' <= str2[i+1] && str2[i+1] <= 'z'))
            {
                string tmp = str2.substr(i, 2);
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                B[tmp]++;
            }
        }

    }

    for(auto item : A) // 교집합
    {    
        if(B[item.first] > 0)
            inter += min(item.second, B[item.first]);
    }

    for(auto item : A) // 합집합
    {      
        if(B[item.first] > 0)
            uni += max(item.second, B[item.first]);
        else
            uni += item.second;
    }

    for(auto item : B) // 합집합
    {    
        if(A[item.first] > 0)
            continue;
        else
            uni += item.second;    
    }

    if(uni == 0)
        answer = 65536;
    else
        answer = (long long)((inter / uni) * 65536.0);

    return answer;
}