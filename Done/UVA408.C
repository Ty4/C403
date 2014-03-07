/* by Tyler Davidson
 *
 * Uniform Generator: 	NONTRIVIAL		(Number Theory)
 *
 * To produce a uniform distribution from 0 to MOD-1, STEP and MOD must be
 * coprime numbers. In other words, gcd(STEP, MOD) must equal 1. That's what
 * this program tests.
 */

#include <iostream>
#include <cstdio>

using namespace std;

int gcd(const int a, const int b){ return b == 0 ? a : gcd(b, a % b); }

int main()
{
	int step, mod;

	while(scanf("%d %d", &step, &mod) == 2){
		printf("%10d%10d    ", step, mod);
		if (gcd(step, mod) == 1)
			printf("Good Choice\n");
		else
			printf("Bad Choice\n");
		printf("\n");
	}

	return 0;
}
