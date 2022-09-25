#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int eratos[3001] = {0} ;
    
    for(int i = 2 ; i <= 3000 ; i++)
    {
        eratos[i]=i;
    }
    
    for(int i = 2; i*i <= 3000; i++)
    {
        if(eratos[i]==0)
        {
            continue;
        }
        else
        {
            for(int j = i*i ; j <= 3000; j += i)
            {
                eratos[j]=0;
            }
        }
    }
    
    for(int i = 0; i < nums_len - 2 ; i++)
    {
        for(int j = i + 1 ; j < nums_len - 1 ; j++)
        {
            for(int k = j + 1 ; k < nums_len ; k++)
            {
                if(eratos[nums[i]+nums[j]+nums[k]] != 0)
                {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}