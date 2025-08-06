# [Silver IV] Umm Code - 18209 

[문제 링크](https://www.acmicpc.net/problem/18209) 

### 성능 요약

메모리: 2872 KB, 시간: 12 ms

### 분류

구현, 문자열, 파싱

### 제출 일자

2025년 8월 6일 17:06:23

### 문제 설명

<p>The current programming club president, Norbit, gives speeches at the weekly club meetings. Casual viewers are underwhelmed with the quality of Norbit’s elocution. Specifically, Norbit often hesitates during his speeches with interjections like “umm.”</p>

<p>You, however, are no casual viewer–you are a computer scientist! You have noticed strange patterns in Norbit’s speech. Norbit’s interjections, when arranged together, form a binary code! By substituting 1’s and 0’s for u’s and m’s, respectively, you produce 7-bit binary ASCII codes that spell out secret messages.</p>

<p>For example, the letter ‘a’ has an ASCII code of 97, which translates to a binary value of 1100001 and an umm code of “uummmmu”. An umm code can be split up in the speech. For example, an encoding of ‘a’ could be stretched across three utterances: “uum”, “mmm”, “u” (possibly with other non-umm code words occurring between them).</p>

<p>Now that you have discovered Norbit’s secret, you go back through transcripts of his previous speeches to decode his cleverly concealed messages.</p>

### 입력 

 <p>There is one line of input of length S (20 ≤ S ≤ 500 000), which ends with a single newline. Before the newline, the input may contain any characters in the ASCII range 32 – 126 (that is, space (‘ ’) through tilde (‘~’)).</p>

<p>Let’s define a “word” as a space-delimited sequence of characters. If a word does not contain any letters or digits except lowercase u’s and/or m’s, then it is part of the umm-coded message. If a word contains digits or letters other than lowercase u and m, then it is not part of the umm-coded message (even if it does contain u or m). Note that a word that is part of the umm-coded message may contain punctuation (which is defined as anything other than letters, digits, or space). Naturally, you should only consider the u and m characters (and not punctuation) when decoding the umm-coded message. Let M be the length of the entire umm-coded message (counting only its u and m characters). It is guaranteed that M ≥ 7 and M is evenly divisible by 7.</p>

### 출력 

 <p>Print the de-umm-coded message. Note that for this problem, the judging is case-sensitive. It is guaranteed that each character that should be output is in the same ASCII range as the input.</p>

