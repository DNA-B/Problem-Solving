button_A,button_B,button_C = 0,0,0
time = int(input())

if(time % 10 != 0):
  print(-1)
else:
    if(time // 300 != 0):
      button_A += (time // 300)
      time -= 300 * (time // 300)
    
    if(time // 60 != 0):
      button_B += (time // 60)
      time -= 60 * (time // 60)

    if(time // 10 != 0):
      button_C += (time // 10)
      time -= 10 * (time // 10)
      
    print(button_A, button_B, button_C)

