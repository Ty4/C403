/* by Tyler Davidson
 *
 * 3n + 1 Problem: NONTRIVIAL
 *
 * This program takes as input two integers. It iterates over each number
 *    within that range, and goes through the cycle with that number.
 * If the length of that cycle is longer than the maximum length found so far,
 *    it becomes the new maximum length.
 * The program outputs the maximum cycle length.
 */

#include <algorithm>
#include <iostream>

using namespace std;

// Outputs the length of the cycle beginning with n
int cycleLength(const int & n_)
{
	short length = 1;
	int n = n_;

	while(n != 1){
		if (n%2 != 0) n = 3*n + 1;
		else n /= 2;
		++length;
	}
	return length;
}

int main()
{
	int i, j;
	int lower, upper;
	while (cin >> i >> j){
		lower = i; upper = j;
		if (lower > upper) swap(lower, upper);

		int max = 0;
		int len;
		for (; lower <= upper; ++lower){
			len = cycleLength(lower);
			if (len > max) max = len;
		}

		cout << i << " " << j << " " << max << endl;
	}

	return 0;
}