/* by Tyler Davidson
 *
 * Flip Sort: 	(Sorting)
 *
 * After the array has been read in, this program looks at each adjacent
 * member in the array and counts each one such that for indeces i, j
 * i < j, && array[i] > array[j]
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// Takes as input the size of the array
// Outputs the minimum number of flips necessary to sort the array
int findFlipsfor(const int N)
{
	int flips = 0;
	vector<int> nums;

	for (int i = 0; i < N; ++i){
		int newNum;
		scanf("%d", &newNum);
		nums.push_back(newNum);
	}

	for (int j = 1; j < N; ++j){
		for (int i = j-1; i >= 0; --i){
			if (nums[i] > nums[j])
				++flips;
		}
	}

	return flips;
}

int main()
{
	int N = 0;

	while (scanf("%d", &N) == 1){
		int flips = 0;
		flips = findFlipsfor(N);

		printf("Minimum exchange operations : %d\n", flips);
	}

	return 0;
}