#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(int x) {
    bool answer = true;
    char trans_char[5];
    int sum = 0;
    
    sprintf(trans_char, "%d", x);
    
    for(int i = 0;i<strlen(trans_char); i++)
    {
        sum += trans_char[i] - '0';
    }
    
    if(x % sum != 0)
    {
        answer = false;
        return answer;
    }
    
    printf("%d의 모든 자릿수의 합은 %d입니다. %d은 %d로 나누어 떨어지므로 %d은 하샤드 수입니다.", x, sum, x, sum, x);
    
    return answer;
}