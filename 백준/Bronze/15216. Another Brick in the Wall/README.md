# [Bronze II] Another Brick in the Wall - 15216 

[문제 링크](https://www.acmicpc.net/problem/15216) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2025년 1월 22일 23:54:12

### 문제 설명

<p>The construction worker previously known as Lars has many bricks of height 1 and different lengths, and he is now trying to build a wall of width w and height h. Since the construction worker previously known as Lars knows that the subset sum problem is NP-hard, he does not try to optimize the placement but he just lays the bricks in the order they are in his pile and hopes for the best. First he places the bricks in the first layer, left to right; after the first layer is complete he moves to the second layer and completes it, and so on. He only lays bricks horizontally, without rotating them. If at some point he cannot place a brick and has to leave a layer incomplete, then he gets annoyed and leaves. It does not matter if he has bricks left over after he finishes.</p>

<p>Yesterday the construction worker previously known as Lars got really annoyed when he realized that he could not complete the wall only at the last layer, so he tore it down and asked you for help. Can you tell whether the construction worker previously known as Lars will complete the wall with the new pile of bricks he has today?</p>

### 입력 

 <p>The first line contains three integers h, w, n (1 ≤ h ≤ 100, 1 ≤ w ≤ 100, 1 ≤ n ≤ 10 000), the height of the wall, the width of the wall, and the number of bricks respectively. The second line contains n integers x<sub>i</sub> (1 ≤ x<sub>i</sub> ≤ 10), the length of each brick.</p>

### 출력 

 <p>Output YES if the construction worker previously known as Lars will complete the wall, and NO otherwise.</p>

