# [Bronze I] 크레이지 타임 - 27161 

[문제 링크](https://www.acmicpc.net/problem/27161) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현(implementation), 시뮬레이션(simulation)

### 문제 설명

<p>우주 어딘가에는 <strong>시간을 셈</strong>으로써 시간이 흐르도록 만들어 주는 존재들이 있습니다. 영겁의 시간을 살아온 그들은 더 재미있게 시간을 세기 위해 시간을 세는 게임을 만들어 냈답니다. 그게 바로 <strong>《크레이지 타임》</strong>이죠!</p>

<p>《크레이지 타임》을 시작하기 전에, 시간 카드를 잘 섞은 후 플레이어들이 최대한 비슷한 수량의 카드를 받도록 나눠 가집니다. 시간 카드는 앞면과 뒷면이 구분된 카드로, 앞면에는 시계 그림과 시각이 적혀 있습니다. 시계의 그림은 총 세 가지로, 벽시계, 손목시계, 그리고 모래시계입니다. 그렇게 받은 카드를 뒷면이 보이도록 자기 앞에 쌓아서 개인 더미를 만듭니다.</p>

<p>게임의 진행은 아래과 같습니다.</p>

<ol>
	<li>플레이어는 자기 차례가 되면 개인 더미의 가장 윗장 카드를 펼치며 이번 순서의 시각을 외칩니다. 첫 플레이어는 "1시"로 시작합니다.</li>
	<li>시계 방향으로 돌아가며 각자의 차례를 가집니다. 다른 방해 요소가 없다면 방금 전에 불린 시각을 기준으로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>시간씩 더해서 외칩니다. 전에 외친 시각이 "12시"라면 다음 사람은 "1시"를 외칩니다.</li>
</ol>

<p>단, 펼쳐진 카드에 따라 색다른 방식으로 외치거나 행동해야 할 수 있습니다. 다양한 시간의 법칙이 게임에 영향을 미치게 되는데, 기본적으로 다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container>가지 종류의 시간의 법칙을 지켜야 합니다.</p>

<ol>
	<li><strong>시간 역행의 법칙</strong>: 누군가 모래시계 카드를 펼치면 시간이 거꾸로 흐르기 시작합니다. "2시", "1시", "12시" 순으로 외쳐야 합니다. 모래시계 카드가 펼쳐질 때마다 시간의 흐름은 반전됩니다.</li>
	<li><strong>동기화의 법칙</strong>: 플레이어가 외친 시각과 펼쳐진 카드에 적힌 시각이 일치하면, 모든 플레이어들은 즉시 손바닥으로 게임판 중앙을 내리쳐야 합니다.</li>
</ol>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d0e873b5-81e6-4221-bad9-96b0c050a625/-/preview/" style="width: 620px; max-width: 100%;"></p>

<p style="text-align: center;">그림 C.1: 시간 역행의 법칙 - 모래시계 카드를 펼치면 시간이 거꾸로 흐르기 시작합니다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6b23f1fb-d978-470a-bb82-241f484300cf/-/preview/" style="width: 620px; max-width: 100%;"></p>

<p style="text-align: center;">그림 C.2: 동기화의 법칙 - 외친 시각과 펼쳐진 카드에 적힌 시각이 일치하면 게임판 중앙을 내리칩니다.</p>

<p>또한 게임에서 <strong>반드시</strong> 지켜져야 하는 하나의 <strong>원칙</strong>이 존재합니다.</p>

<ol>
	<li><strong>과부하의 원칙</strong>: 펼쳐지는 카드가 동시에 2개 이상의 법칙을 발동시킨다면, 그 어떤 법칙도 적용하지 않습니다. 예를 들어, 시간 역행의 법칙과 동기화의 법칙이 동시에 발동되면, 그 어떠한 법칙도 적용하지 않습니다.</li>
</ol>

<p>잘못된 시각을 외치거나 손바닥을 가장 늦게 내리친 플레이어는 벌점 토큰을 받아 자기 카드 더미 옆에 놓습니다. 벌점 토큰이 주어지고 나면, 플레이어들은 펼쳐진 카드들을 다시 각자의 카드 더미 밑으로 넣습니다. 그런 다음 벌점을 받은 플레이어가 "1시"를 외치며 경기를 재개합니다.</p>

<p>《크레이지 타임》을 너무나도 좋아하는 한별이는 은하에게 이기기 위해 여러분에게 도움을 청했습니다. 한별이는 마법을 써서 다음 차례의 플레이어가 펼칠 카드를 전부 알아냈습니다. 뛰어난 《크레이지 타임》 플레이어인 은하는 절대로 잘못된 시각을 외치지 않기 때문에, 해당 방법으로 벌점 토큰이 주어지지는 않습니다. 또한 동기화의 법칙이 적용되었을 때 모든 플레이어는 정확히 같은 순간에 손바닥을 내리치게 되는데, 누가 마지막으로 내리쳤는지 알기 어렵기 때문에 실제 게임과는 다르게 아무도 벌점 토큰을 받지 않고 게임을 진행하기로 결정하였습니다. 펼쳐질 카드들의 순서가 주어졌을 때, 각 차례의 플레이어가 외쳐야 하는 시각과 해야 하는 행동을 알려주세요.</p>

### 입력 

 <p>첫 번째 줄에 펼쳐질 카드의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어집니다.</p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 걸쳐 한 줄에 하나씩 카드의 정보가 주어집니다.</p>

<p>카드의 정보는 공백으로 구분된, 카드에 그려진 시계의 종류를 나타내는 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>와 카드에 적힌 시간을 나타내는 양의 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$X$</span></mjx-container>로 이루어져 있습니다. </p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>는 <span style="color:#e74c3c;"><code>CLOCK</code></span>, <span style="color:#e74c3c;"><code>WATCH</code></span>, <span style="color:#e74c3c;"><code>HOURGLASS</code></span> 중 하나입니다.</p>

<p><span style="color:#e74c3c;"><code>CLOCK</code></span>은 벽시계를, <span style="color:#e74c3c;"><code>WATCH</code></span>는 손목시계를, <span style="color:#e74c3c;"><code>HOURGLASS</code></span>는 모래시계를 의미합니다.</p>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐 해당 카드를 펼쳤을 때 차례를 진행하는 플레이어가 외쳐야 하는 시각과 해야 하는 행동을 공백으로 구분하여 출력해주세요.</p>

<p>시각은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>12</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$12$</span></mjx-container> 사이의 정수로, 해야 하는 행동은 게임판 중앙을 내리쳐야 한다면 <span style="color:#e74c3c;"><code>YES</code></span>를, 아니면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력해주세요.</p>

