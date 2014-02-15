/* by Tyler Davidson
 *
 * Brick Wall Problem: 		(Combinatorics)
 *
 * This program is solved via a simple application of the fibonacci sequence.
 *
 */

#include <cstdio>

#define MAX 51
#define ll long long

ll fib[MAX];

int main()
{
	int n;

	fib[0] = fib[1] = 1;
	for (int i = 2; i < MAX; ++i)
		fib[i] = fib[i-1] + fib[i-2];

	scanf("%d", &n);
	while (n != 0)
	{
		printf("%lld\n", fib[n]);
		scanf("%d", &n);
	}
}
