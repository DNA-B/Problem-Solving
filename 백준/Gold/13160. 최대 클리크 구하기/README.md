# [Gold III] 최대 클리크 구하기 - 13160 

[문제 링크](https://www.acmicpc.net/problem/13160) 

### 성능 요약

메모리: 38472 KB, 시간: 708 ms

### 분류

정렬, 스위핑, 값 / 좌표 압축

### 제출 일자

2025년 7월 14일 08:02:28

### 문제 설명

<p>그래프 이론에서 클리크란, 완전 그래프인 부분 그래프를 의미한다. 즉, 정점으로 이루어진 집합 중 모든 두 정점 사이에 간선이 있는 집합을 의미한다. 최대 클리크는 그러한 집합 중 크기가 가장 큰 집합을 말한다. 일반적인 그래프에서 최대 클리크를 구하는 문제는 NP-hard 이다.</p>

<p>N개의 구간이 있다. i번 구간의 시작점은 S<sub>i</sub>, 끝점은 E<sub>i</sub>이며, 어떤 두 구간이 한 점 이상을 공유하면 이 두 구간을 ‘겹친다’고 표현한다. 이때 우리는 구간 그래프를 정의할 수 있다. 구간 그래프란, N개의 정점이 있고, i번 구간과 j번 구간이 겹칠 때, i번 정점과 j번 정점 사이에 간선이 존재하는 그래프다. 만약 두 구간이 겹치지 않는다면 i번 정점과 j번 정점 사이에 존재하는 간선은 없다.</p>

<p>예를 들어 위와 같이 N개의 구간이 있을 때 이를 구간 그래프로 나타내면 아래와 같다.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13160/1.png" style="height:110px; width:396px"></p>

<p>이때 이 구간 그래프의 최대 클리크는 {1, 2, 4}이다.</p>

<p style="text-align:center"><img alt="" src="https://upload.acmicpc.net/d51c0ffb-3c0e-494a-a829-47ca38f452dc/-/preview/" style="width: 241px; height: 134px;"></p>

<p>N개의 구간이 주어졌을 때, 이에 대한 구간 그래프의 최대 클리크를 구하시오.</p>

### 입력 

 <p>입력의 첫 줄에는 구간의 수를 나타내는 자연수 N(1 ≤ N ≤ 300,000)이 주어진다. 다음 N개의 줄에 각 구간의 시작점과 끝점을 나타내는 두 자연수 S<sub>i</sub>, E<sub>i</sub>가 공백으로 구분되어 주어진다. (1 ≤ S<sub>i</sub> < E<sub>i</sub> ≤ 10<sup>9</sup>)</p>

### 출력 

 <p>첫 줄에 최대 클리크의 크기 s를 출력한다. 둘째 줄에는 클리크에 있는 정점들의 번호 s개를 공백으로 구분하여 출력한다. 출력 순서는 상관없으며, 만약 최대 클리크가 여러 가지인 경우 그 중 아무거나 출력한다.</p>

