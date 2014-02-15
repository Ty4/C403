	/* by Tyler Davidson
 *
 * Hats:		(Combinatorics)
 *
 * This program uses derangement to find the number of cases where people take
 * the wrong hat, and factorial to find the number of possibilities.
 */

#include <cstdio>
#include <iostream>

using namespace std;

#define ll long long

int cases;
ll people;

ll derangement(const ll n)
{
	if (n == 0) return 1;
	if (n == 1) return 0;
	ll pt1 = derangement(n-1);
	ll pt2 = derangement(n-2);

	return (n-1)*(pt1 + pt2);
}

ll fact(const int n)
{
	ll res = 1;
	for (int i = n; i > 1; --i)
		res *= i;
	return res;
}

int main()
{
	scanf("%d", &cases);
	for (int i = 0; i < cases; ++i){
		ll est;
		scanf("%lld", &people);

		est = derangement(people);

		printf("%lld/%lld\n", est, fact(people));
	}

	return 0;
}
