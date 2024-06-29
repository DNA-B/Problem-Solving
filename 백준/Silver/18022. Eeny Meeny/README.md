# [Silver III] Eeny Meeny - 18022 

[문제 링크](https://www.acmicpc.net/problem/18022) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

자료 구조, 덱, 구현

### 제출 일자

2024년 6월 29일 23:18:18

### 문제 설명

<p>“Eeny meeny miny moe” is a well-known nursery rhyme in English, used (among other things) by kids to “randomly” select members of a team. It exists in many variations, one of which goes like this:</p>

<blockquote>
<p>Eeny, meeny, miny, moe,<br>
Catch a tiger by the toe.<br>
If he hollers, let him go,<br>
Eeny, meeny, miny, moe.</p>
</blockquote>

<p>Similar verses exist in most languages, such as “Ulle dulle dof” in Finnish, “Akka bakka bonka rakka” in Norwegian, and “Ole dole doff” in Swedish.</p>

<p>Two teams are to be selected for a game and the rhyme is used to select one kid for a team at a time, alternating between the two teams, until all kids have been selected. The kids are standing in a circle. In each selection round we start counting the kids in clockwise order around the circle, skipping one kid for every word in the rhyme, until the last word. The kid matching the last word is chosen for the current team and then the next round starts. In all rounds but the first, the counting starts at the next remaining kid (in clockwise order) after the one that was selected in the previous round. See Figure E.1 for an example.</p>

<p>Given such a rhyme, and a group of kids, can you tell which kids will be in which team?</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/00be2ded-b260-4311-99a1-a1d3da66c3cb/-/preview/" style="width: 615px; height: 189px;"></p>

<p>Figure E.1: Illustration of the first three rounds of Sample Input 1. In rounds 1 and 3, Alvar and Rakel get selected for the first team, and in round 2, Lisa is selected for the second team. In round 4 (not shown), only Kalle remains and is selected for the second team.</p>

### 입력 

 <p>The first line of input contains the rhyme, consisting of a list of words separated by spaces. The second line of input contains an integer n (1 ≤ n ≤ 100), the number of kids. Then follow the names of the kids, one per line. The kids are given in clockwise order and the first kid listed is the one at which counting starts in the first round.</p>

<p>All words and names consist only of upper and lower case letters ‘A’-‘Z’ and ‘a’-‘z’. No input line is empty or longer than 100 characters (excluding the newline character at the end of the line).</p>

### 출력 

 <p>Output the two teams, starting with the one whose first member is chosen first. For each team, output the number of kids in the team, followed by the names of the kids in the team, in the same order as they were chosen for the team.</p>

