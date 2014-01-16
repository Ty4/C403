/* by Tyler Davidson
 *
 * Ugly Numbers Problem NONTRIVIAL
 *
 * An ugly number is a number where the only prime factors are 2, 3, or 5.
 * This progam begins with 1 as the first ugly number. The next number is
 *   computed only by looking at multiples of 2, 3, or 5, and taking the lowest
 *   of the three multiples.
 */

#include <iostream>
#include <vector>

using namespace std;

// returns the minimum of three numbers
long min (long a, long b, long c)
{
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	return c;
}

// computes the nth ugly number
long nthUglyNumber(const int & n)
{
	vector<long> ugNum; ugNum.push_back(1);
	int i2, i3, i5; i2 = i3 = i5 = 0; // array indeces

	long next2 = ugNum[i2]*2;
	long next3 = ugNum[i3]*3;
	long next5 = ugNum[i5]*5;

	long nextUgNum;

	for (int i = 1; i < n; ++i){
		nextUgNum = min(next2, next3, next5);
		ugNum.push_back(nextUgNum);
		if (nextUgNum == next2){
			++i2;
			next2 = ugNum[i2]*2;
		}
		if (nextUgNum == next3){
			++i3;
			next3 = ugNum[i3]*3;
		}
		if (nextUgNum == next5){
			++i5;
			next5 = ugNum[i5]*5;
		}
	}

	return ugNum[n-1];
}

int main()
{
	long num = nthUglyNumber(1500);

	cout << "The 1500'th ugly number is " << num << ".\n";

	return 0;
}