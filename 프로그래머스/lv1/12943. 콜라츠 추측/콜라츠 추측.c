#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(long long num) {
    int answer = 0;
    
    while(num != 1)
    {
        if(answer == 500)
        {
            return -1;
        }
        
        if(num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num = (num * 3) + 1;
        }
        
        answer++;
    }
    printf("%d", num);
    return answer;
}