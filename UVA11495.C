/* by Tyler Davidson
 *
 * Bubbles and Buckets:		(Sorting)
 *
*/

#import <cstdio>
#import <iostream>
#import <vector>

using namespace std;

typedef struct MergeResult
{
	int invs;
	vector<int> workArray;

	MergeResult() : invs(0) {}

	MergeResult(const vector<int> A)
	{
		invs = 0;
		workArray = A;
	}

	MergeResult & operator+=(const MergeResult &rhs)
	{
		invs += rhs.invs;
		return *this;
	}

} MergeResult;

MergeResult BottomUpMerge(vector<int> A, int iLeft, int iRight, int iEnd)
{
	int i0 = iLeft;
	int i1 = iRight;
	int j;
	MergeResult result(A);

	for (j = iLeft; j < iEnd; j++){
		if (i0 < iRight && (i1 >= iEnd || A[i0] <= A[i1])){
			result.workArray[j] = A[i0];
			i0 = i0 + 1;
		}
		else{
			if (A[i0] > A[i1])
				result.invs += 1;
			result.workArray[j] = A[i1];
			i1 = i1 + 1;
		}
	}
	// cout << "In merge->result.inv: " << result.invs << endl;
	return result;
}

int playGame(vector<int> nums)
{
	int inversions = 0;
	int n = nums.size();
	MergeResult result(nums);

	for (int width = 1; width < n; width = 2 * width){
		for (int i = 0; i < n; i = i + 2 * width){
			result = BottomUpMerge(nums, i,
				min(i+width, n), min(i+2*width, n));
			inversions += result.invs;
		}
		nums = result.workArray;

	}

	// cout << inversions << endl;
	return result.invs;
}

int main()
{
	int N;
	int result;

	scanf("%d", &N);
	while(N != 0){
		vector<int> gameNums;
		for (int i = 0; i < N; ++i){
			int num;
			scanf("%d", &num);
			gameNums.push_back(num);
		}

		result = playGame(gameNums);
		if (result % 2 == 0)
			cout << "Carlos" << endl;
		else
			cout << "Marcelo" << endl;
		scanf("%d", &N);
	}

	return 0;
}