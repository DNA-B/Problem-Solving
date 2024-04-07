#define _CRT_SECURE_NO_WARNINGS
#define GOAL 100
#include <bits/stdc++.h>

using namespace std;

int N, M;
int alpha[26] = { 0 };

void howManyUsedAlphabet(char _a) {
	switch (_a) {
		case 'a':
		case 'A':
			alpha[0]++; break;
		case 'b':
		case 'B':
			alpha[1]++; break;
		case 'c':
		case 'C':
			alpha[2]++; break;
		case 'd':
		case 'D':
			alpha[3]++; break;
		case 'e':
		case 'E':
			alpha[4]++; break;
		case 'f':
		case 'F':
			alpha[5]++; break;
		case 'g':
		case 'G':
			alpha[6]++; break;
		case 'h':
		case 'H':
			alpha[7]++; break;
		case 'i':
		case 'I':
			alpha[8]++; break;
		case 'j':
		case 'J':
			alpha[9]++; break;
		case 'k':
		case 'K':
			alpha[10]++; break;
		case 'l':
		case 'L':
			alpha[11]++; break;
		case 'm':
		case 'M':
			alpha[12]++; break;
		case 'n':
		case 'N':
			alpha[13]++; break;
		case 'o':
		case 'O':
			alpha[14]++; break;
		case 'p':
		case 'P':
			alpha[15]++; break;
		case 'q':
		case 'Q':
			alpha[16]++; break;
		case 'r':
		case 'R':
			alpha[17]++; break;
		case 's':
		case 'S':
			alpha[18]++; break;
		case 't':
		case 'T':
			alpha[19]++; break;
		case 'u':
		case 'U':
			alpha[20]++; break;
		case 'v':
		case 'V':
			alpha[21]++; break;
		case 'w':
		case 'W':
			alpha[22]++; break;
		case 'x':
		case 'X':
			alpha[23]++; break;
		case 'y':
		case 'Y':
			alpha[24]++; break;
		case 'z':
		case 'Z':
			alpha[25]++; break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	char str[1000001];

	char mostUsedAlphabet = 65;
	int most = 0, length = 0;

	cin >> str;
	while (str[length] != '\0') {
		length++;
	}

	for (int i = 0; i < length; i++) {
		howManyUsedAlphabet(str[i]);
	}

	for (int i = 0; i < 26; i++) {
		if (most < alpha[i]) {
			mostUsedAlphabet = i + 65;
			most = alpha[i];
		}
		else if (most == alpha[i]) {
			mostUsedAlphabet = '?';
		}
	}
	cout << mostUsedAlphabet;

	return 0;
}