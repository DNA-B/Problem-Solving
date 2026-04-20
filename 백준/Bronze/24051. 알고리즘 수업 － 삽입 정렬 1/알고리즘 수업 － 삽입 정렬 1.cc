#include <iostream>
using namespace std;

int insertion_sort(int N, int K, int A[]);

// 삽입 정렬
int insertion_sort(int N, int K, int A[]) {
    int count = 0; // 저장 횟수

    //A[]을 오름차순 정렬한다.
    for (int i = 1; i < N; i++) {
        int loc; 
        int newItem = A[i];

        // 이 지점에서 A[1..i - 1]은 이미 정렬되어 있는 상태
        for (loc = i - 1; loc >= 0 && newItem < A[loc]; loc--) {
            A[loc + 1] = A[loc];
            count++;

            // K 번째 저장
            if (count == K) return A[loc + 1];
        }

        if (loc + 1 != i) {
            A[loc + 1] = newItem;
            count++;

            // K 번째 저장
            if (count == K) return A[loc + 1];
        }
    }

    return -1;
}

int main() {
	int N, K; //  배열의 크기 N, 저장 횟수 K
	scanf("%d %d", &N, &K);

    int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

    // 출력
	cout << insertion_sort(N, K, A) << endl;

	return 0;
}