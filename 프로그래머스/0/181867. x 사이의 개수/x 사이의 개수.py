def solution(myString):
    answer = []
    
    for s in myString.split('x'):
        answer.append(len(s))

    return answer