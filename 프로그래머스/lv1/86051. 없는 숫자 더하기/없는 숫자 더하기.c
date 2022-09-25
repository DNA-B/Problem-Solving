#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = -1;
    int arr_sum = 0;
    
    for(int i = 0;i<numbers_len;i++)
    {
        arr_sum += numbers[i];
    }
    
    answer = 45 - arr_sum;
    
    if(answer == 0)
    {
        return -1;
    }
    
    return answer;
}