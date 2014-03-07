/* by Tyler Davidson
 *
 * Factors and Factorials: 		NONTRIVIAL		(Number Theory)
 *
 * This is essentially a simple prime factorization question, but the factoring
 * is already taken care of by the nature of the factorial function. Instead,
 * the algorithm finds the prime factors of each number from 2->n and adds each
 * to the total.
 */

#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

map<int,int> primeFreq;

void primeFact(const int x)
{
	int i;
	int c;

	c = x;
	i = 2;
	while((c%2) == 0){
		primeFreq[i] += 1;
		c /= 2;
	}

	i = 3;
	while (i <= (sqrt(c)+1)){
		if ((c%i) == 0){
			primeFreq[i] += 1;
			c /= i;
		}
		else
			i += 2;
	}

	if (c > 1)
		primeFreq[c] += 1;
}

int main()
{
	int n;

	scanf("%d", &n);
	while (n != 0){
		for (int i = 2; i <= n; ++i)
			primeFact(i);

		printf("%3d! =", n);

		int cnt = 1;;
		for (auto it : primeFreq){
			if (cnt % 16 == 0)
				printf("\n      ");
			printf("%3d", it.second);
			++cnt;
		}
		printf("\n");
		primeFreq.clear();
		scanf("%d", &n);
	}

	return 0;
}
