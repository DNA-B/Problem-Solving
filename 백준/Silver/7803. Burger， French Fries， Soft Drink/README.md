# [Silver III] Burger, French Fries, Soft Drink - 7803 

[문제 링크](https://www.acmicpc.net/problem/7803) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

수학, 문자열, 조합론

### 제출 일자

2025년 9월 7일 03:50:23

### 문제 설명

<p>Anna works as a waitress at a popular fast-food restaurant in Indonesia, “Om Burger”. Her job is much easier than any waiters/waitresses at other fast-food restaurants, because Om Burger owns an automatic fast-food machine.</p>

<p>Om Burger serves only a single combo-menu package named Paket Uenak, which consists of three items: 1 Burger (B), 1 French Fries (F), and 1 Soft Drink (S). Each customer would be given a card to write the number of Paket Uenak packages to be ordered. The card should be given back to Anna who will insert it into the machine. The machine will prepare all items of each package one by one according to the written number on the card, but not necessary in any particular order of item. For example, if the number 2 (means 2 Paket Uenak packages are ordered by a customer) is written on the card, the machine will prepare items in the sequence of BBFFSS, or any of its permutation (BFSBFS, BBFSFS, etc). There could be more than one card to be processed by the machine at a time. However the machine will process all cards sequentially. That means it will not proceed to the next card before finishing the current card.</p>

<p>One day, some customers are queuing to put their orders. While they make a quite long queue, it gives Anna an idea. Instead of inserting the card one by one, she initiatively inserts more than one card at a time. Brilliant, isn’t she? Well, let’s see what happens next. The machine does work well, but now she doesn’t have any idea which item belongs to which card, because the machine doesn’t give any separations to separate packages from different cards.</p>

<p>Fortunately, Anna still remembers the number of cards inserted and its sequence (which card belongs to whom). However, she doesn’t remember the number of Paket Uenak packages written on each card.</p>

<p>For example, if there are two cards inserted into the machine:</p>

<ul>
	<li>Prepared : B B F S S F S F B B F S</li>
	<li>Possibility-1 : (B B F S S F) ( S F B B F S), the first customer ordered 2 Paket Uenak packages, and the second customer ordered 2 Paket Uenak packages.</li>
	<li>Possibility-2 : (B B F S S F S F B) (B F S), the first customer ordered 3 Paket Uenak packages, and the second customer ordered 1 Paket Uenak package.</li>
</ul>

<p>No need to tell, that now she’s apologizing and questioning all customers for what they have been ordering again. But this problem has aroused her curiosity as she is also a student in Computer Science. Help Anna to find how many possible order arrangements could be found from any given condition(s).</p>

### 입력 

 <p>Each line of input contains an integer N (1 < N < 30) denoting the number of card(s) inserted, and a string which contains character(s) of B, F, and S (no spaces) denoting the order of items prepared by the machine. You may assume that the length of each string is less than 100.</p>

<p> </p>

### 출력 

 <p>For each line of input, print the number of possible order arrangements could be found. If there is no possible order arrangement, output "Impossible" (without quotes).</p>

<p> </p>

