/* by Tyler Davidson
 *
 * Find the Ways!: 		(Combinatorics)
 *
 * This program uses common logarithms to find the number of digits in an
 * n choose k number.
 */

#include <cmath>
#include <iostream>

using namespace std;


int n, k;

int findNumberofDigits(const int n, const int k)
{
	double num = 0;
	for (int i = n; i > n - k; --i){
    	num += log10(i);
	}
	for (int i = k; i > 0; --i){
    	num -= log10(i);
    }
    return floor(num) + 1;
}

int main()
{
	while (cin >> n >> k)
	{
		if (n-k < k) k = n - k;
		cout << findNumberofDigits(n, k) << endl;
	}

	return 0;
}
