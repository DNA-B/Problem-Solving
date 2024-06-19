# [Silver II] TRAKTOR - 10645 

[문제 링크](https://www.acmicpc.net/problem/10645) 

### 성능 요약

메모리: 16016 KB, 시간: 180 ms

### 분류

기하학, 구현, 정렬

### 제출 일자

2024년 6월 19일 19:43:08

### 문제 설명

<p>Mirko got a supercool new tractor for Christmas that can even pick mushrooms! The mushrooms grow on a square-shaped meadow that can be placed in a coordinate plane so that its lower left edge is located at (1, 1) and its upper right edge at (10<sup>5</sup>, 10<sup>5</sup>).</p>

<p>Initially, there are no mushrooms on the meadow, but in total N will grow in a way that each second exactly one new mushroom grows on an empty space on the meadow.</p>

<p>Economical Mirko wants to ride his tractor only once and pick at least K mushrooms. His ride begins at one of the points on the meadow and he can move only in directions parallel to its sides or diagonals. Mirko’s tractor is super fast and travels great distances in negligible time. Because of the enormous speed, Mirko can’t make turns during the ride.</p>

<p>Help Mirko and determine the minimal number of seconds after which he can pick the wanted number of mushrooms.</p>

### 입력 

 <p>The first line of input contains the integers N (2 ≤ N ≤ 10<sup>6</sup>) and K (2 ≤ K ≤ N), the number of mushrooms that will grow and the number of mushrooms Mirko wants to pick.</p>

<p>Each of the following N lines contains two integers Xi and Yi (1 ≤ Xi, Yi ≤ 10<sup>5</sup>), the coordinates of the ith mushroom grown on that meadow.</p>

### 출력 

 <p>The first and only line of output must contain the required minimal number of seconds. If Mirko can’t pick K mushrooms in one ride, output -1.</p>

