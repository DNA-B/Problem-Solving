def solution(my_string):
    answer = []
    my_string = my_string.strip()
    
    for s in my_string.split(" "):
        if s != "":
            answer.append(s)
            
    return answer