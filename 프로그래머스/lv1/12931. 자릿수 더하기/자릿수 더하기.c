#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int n) {
    int answer = 0;
    char* trans_n = (char*)malloc(1);
    
    sprintf(trans_n, "%d", n);
    
    for(int i = 0; i < strlen(trans_n); i++)
    {
        answer += trans_n[i] - '0';
    }
    
    free(trans_n);
    
    return answer;
}