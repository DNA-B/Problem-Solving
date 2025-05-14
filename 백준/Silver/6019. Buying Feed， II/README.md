# [Silver III] Buying Feed, II - 6019 

[문제 링크](https://www.acmicpc.net/problem/6019) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

정렬

### 제출 일자

2025년 5월 15일 06:26:15

### 문제 설명

<p>Farmer John needs to travel to town to pick up K (1 <= K <= 100) pounds of feed. Driving D miles with K pounds of feed in his truck costs D*K cents.</p>

<p>The county feed lot has N (1 <= N <= 100) stores (conveniently numbered 1..N) that sell feed. Each store is located on a segment of the X axis whose length is E (1 <= E <= 350). Store i is at location X_i (0 < X_i < E) on the number line and can sell FJ as much as F_i (1 <= F_i <= 100) pounds of feed at a cost of C_i (1 <= C_i <= 1,000,000) cents per pound. Amazingly, a given point on the X axis might have more than one store.</p>

<p>FJ starts at location 0 on this number line and can drive only in the positive direction, ultimately arriving at location E, with at least K pounds of feed. He can stop at any of the feed stores along the way and buy any amount of feed up to the the store's limit.</p>

<p>What is the minimum amount FJ has to pay to buy and transport the K pounds of feed? FJ knows there is a solution.</p>

<p>Consider a sample where FJ needs two pounds of feed from three stores (locations: 1, 3, and 4) on a number line whose range is 0..5:</p>

<pre>      0   1   2   3   4   5
      +---|---+---|---|---+
          1       1   1      Available pounds of feed
          1       2   2      Cents per pound</pre>

<p>It is best for FJ to buy one pound of feed from both the second and third stores. He must pay two cents to buy each pound of feed for a total cost of 4. When FJ travels from 3 to 4 he is moving 1 unit of length and he has 1 pound of feed so he must pay 1*1 = 1 cents.</p>

<p>When FJ travels from 4 to 5 he is moving one unit and he has 2 pounds of feed so he must pay 1*2 = 2 cents.</p>

<p>The total cost is 4+1+2 = 7 cents.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: K, E, and N</li>
	<li>Lines 2..N+1: Line i+1 contains three space-separated integers: X_i, F_i, and C_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the minimum cost for FJ to buy and transport the feed</li>
</ul>

<p> </p>

