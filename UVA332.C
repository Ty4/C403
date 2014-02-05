/* by Tyler Davidson
 *
 * Rational Numbers from Repeating Fractions:	NONTRIVIAL 	(Arithmetic)
 *
 */

#include <boost/algorithm/string.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::algorithm;

int findNumer(const int j, const int k, const double & X)
{
	if (X == 0) return 0;
	else{
		int jkpow = pow(10, k+j) * X;
		int kpow = pow(10, k) * X;
		return jkpow - kpow;
	}
}

int findDenom(const int j, const int k)
{
	//cout << "Finding denominator using " << j << " and " << k << endl;
	return ((pow(10, k+j)) - pow(10, k));
}

int findGcd(const int num, const int den)
{
	return den == 0 ? num : findGcd(den, num % den);
}

int main()
{
	int caseNum = 1;
	int j,k;

	scanf("%d", &j);
	while (j != -1){
		int numer, denom, gcd;
		double x;
		string numstr;
		x = 0;

		int dig;
		while ((dig = getchar()) != '.');
		while (dig != '\n'){
			numstr.push_back(dig);
			dig = getchar();
		}
		trim_right(numstr);
		k = numstr.size() - j - 1;
		x += atof(numstr.c_str());

		numer = findNumer(j,k,x); denom = findDenom(j,k);
		gcd = findGcd(numer, denom);

		if (numer == 0)
			printf("Case %d: 0/1\n", caseNum++);
		else
			printf("Case %d: %d/%d\n", caseNum++, numer/gcd, denom/gcd);
		scanf("%d", &j);
	}
	return 0;
}
