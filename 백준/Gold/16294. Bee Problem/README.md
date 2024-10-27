# [Gold V] Bee Problem - 16294 

[문제 링크](https://www.acmicpc.net/problem/16294) 

### 성능 요약

메모리: 7364 KB, 시간: 52 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 10월 27일 19:13:01

### 문제 설명

<p>You are a busy little bee, and you have a problem. After collecting nectar all day long, you are returning to the beehive with a large supply of honey. You would really like to take a nap now, but sadly, you have to store all the honey in your beehive first. Opening up a cell in the hive to funnel honey into takes a lot of time, so you want to avoid doing this as much as possible.</p>

<p>Some of the cells in the beehive are already filled with old, hardened honey. The other cells are still empty. If you pour honey into an empty cell, it will automatically start flowing into adjacent empty cells. From these cells, the honey will again flow to other neighbouring empty cells. This saves you from having to funnel honey into them directly. You decide to use this to your advantage, by pouring into cells with lots of (indirect) adjacent open cells.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a5884c0c-7004-41a7-bb5a-427a33f8334a/-/preview/" style="width: 457px; height: 145px;"></p>

<p style="text-align: center;">Figure 1: The beehives from the first two samples. The black hexagons already contain hardened honey. The white cells are still empty.</p>

<p>You have some units of honey, and know the layout of your beehive. By cleverly choosing which cells to funnel honey into, what is the minimal amount of work you have to do?</p>

### 입력 

 <ul>
	<li>The input starts with three integers, 0 ≤ h ≤ 10<sup>6</sup>, the amount of honey you have, and 1 ≤ n, m ≤ 10<sup>3</sup>, the dimensions of the grid.</li>
	<li>Then follow n lines, one for each row of the grid. Each row has m symbols, either <code>.</code>, representing an empty cell, or <code>#</code>, representing a filled cell. These symbols are separated by spaces. Furthermore, every second row starts with a space, as these are slightly offset to the right.</li>
</ul>

<p>The grid always has enough open cells to store all your honey.</p>

### 출력 

 <p>Output a single integer, the number of cells you have to funnel honey into directly to store all your honey in the hive.</p>

