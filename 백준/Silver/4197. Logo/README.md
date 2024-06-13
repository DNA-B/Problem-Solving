# [Silver IV] Logo - 4197 

[문제 링크](https://www.acmicpc.net/problem/4197) 

### 성능 요약

메모리: 2080 KB, 시간: 8 ms

### 분류

기하학, 구현, 수학, 시뮬레이션

### 제출 일자

2024년 6월 12일 20:51:53

### 문제 설명

<p>Logo is a programming language built around a turtle. Commands in the language cause the turtle to move. The turtle has a pen attached to it. As the turtle moves, it draw lines on the page. The turtle can be programmed to draw interesting pictures.</p>

<p>We are interested in making the turtle draw a picture, then return to the point that it started from. For example, we could give the turtle the following program:</p>

<pre>fd 100 lt 120 fd 100 lt 120 fd 100</pre>

<p>The command fd causes the turtle to move forward by the specified number of units. The command lt causes the turtle to turn left by the specified number of degrees. Thus the above commands cause the turtle to draw an equilateral triangle with sides 100 units long. Notice that after executing the commands, the turtle ends up in the same place as it started. The turtle understands two additional commands. The command bk causes the turtle to move backward by the specified number of units. The command rt causes the turtle to turn right by the specified number of degrees.</p>

<p>After executing many commands, the turtle can get lost, far away from its starting position. Your task is to determine the straight-line distance from the turtle's position at the end of its journey back to the position that it started from.</p>

### 입력 

 <p>The first line of input contains one integer specifying the number of test cases to follow. Each test case starts with a line containing one integer, the number of commands to follow. The commands follow, one on each line. Each test case will contain no more than 1000 commands.</p>

<p>You can assume that the given degree is greater than or equal to 0 and less than 360.</p>

<p>Also, you can assume that the given distance is greater than 0 and less than 1000000.</p>

### 출력 

 <p>For each test case, output a line containing a single integer, the distance rounded to the nearest unit.</p>

<p>You can assume that answer does not change within an absolute error of 0.01.</p>

