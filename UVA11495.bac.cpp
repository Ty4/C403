/* by Tyler Davidson
 *
 * Bubbles and Buckets:		(Sorting)
 *
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100004

int A[MAXN], B[MAXN];

int BottomUpMerge(int iLeft, int iRight, int iEnd)
{
	int i0 = iLeft;
	int i1 = iRight;
	int inversions = 0;

	for (int j = iLeft; j < iEnd; j++){
		if (i0 < iRight && (i1 >= iEnd || A[i0] <= A[i1])){
			B[j] = A[i0];
			++i0;
		}
		else{
			if (A[i0] > A[i1] && i1 == i0+1)
				inversions += 1;
			B[j] = A[i1];
			++i1;
		}
	}
	return inversions;
}

int playGame(int N)
{
	int inversions = 0;

	for (int width = 1; width < N; width = 2 * width){
		for (int i = 0; i < N; i = i + 2 * width){
			int invs = BottomUpMerge(i,
				min(i+width, N), min(i+2*width, N));
			inversions += invs;
		}
		memcpy(A, B, sizeof(int)*N);
	}
	return inversions;
}

int main()
{
	int N;
	int result;

	scanf("%d", &N);
	while(N != 0){
		for (int i = 0; i < N; ++i)
			scanf("%d", &A[i]);

		result = playGame(N);
		if (result % 2 == 0)
			printf("Carlos\n");
		else
			printf("Marcelo\n");
		scanf("%d", &N);
	}

	return 0;
}